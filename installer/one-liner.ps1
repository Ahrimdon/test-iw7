# Define URL and dynamically extract filename from URL
$url = "https://git.rimmyscorner.com/Rim/iw7-mod/releases/download/latest/iw7Installer.exe"
$file = Split-Path -Path $url -Leaf

# Check if file already exists and delete if necessary
if (Test-Path -Path $file) {
    Write-Host "Removing existing file: $file"
    Remove-Item -Path $file -Force
}

# Download the file using Invoke-WebRequest for better cross-platform compatibility
try {
    Invoke-WebRequest -Uri $url -OutFile $file -ErrorAction Stop
} catch {
    Write-Error "Download failed: $_"
    exit 1
}

# Start the installer with arguments, wait for it to complete
try {
    Start-Process -FilePath $file -ArgumentList "-s" -Wait
} catch {
    Write-Error "Installation failed: $_"
}

# Clean up downloaded file
Remove-Item -Path $file -Force

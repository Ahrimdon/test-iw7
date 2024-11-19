$url = "https://git.rimmyscorner.com/Rim/iw7-mod/releases/download/latest/iw7Installer.exe"
$file = "iw7Installer.exe"

(New-Object System.Net.WebClient).DownloadFile($url, $file)
Start-Process -Wait $file -ArgumentList "-s"
Remove-Item $file

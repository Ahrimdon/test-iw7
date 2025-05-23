#pragma once
#include "types/database.hpp"
#include "types/demonware.hpp"

namespace game
{
	using namespace database;
	using namespace demonware;

	struct XUID
	{
		std::uint64_t m_id;
	};

	enum GameModeType : std::uint32_t
	{
		GAME_MODE_NONE = 0x0,
		GAME_MODE_SP = 0x1,
		GAME_MODE_MP = 0x2,
		GAME_MODE_CP = 0x3,
	};

	enum Com_GameMode_Feature : std::int32_t
	{
		FEATURE_GRAVITY = 33,
		FEATURE_TIMESCALE = 69,
		FEATURE_RANDOM_PLAYERCARD_WHEN_MISSING = 163,
	};

	enum Sys_Folder
	{
		SF_ZONE = 0x0,
		SF_ZONE_LOC = 0x1,
		SF_VIDEO = 0x2,
		SF_VIDEO_LOC = 0x3,
		SF_PAKFILE = 0x4,
		SF_PAKFILE_LOC = 0x5,
		SF_COUNT = 0x6,
	};

	enum errorParm
	{
		ERR_FATAL = 0,
		ERR_DROP = 1,
		ERR_SERVERDISCONNECT = 2,
		ERR_DISCONNECT = 3,
		ERR_SCRIPT = 4,
		ERR_SCRIPT_DROP = 5,
		ERR_LOCALIZATION = 6,
		ERR_MAPLOADERRORSUMMARY = 7,
	};

	struct CmdArgs
	{
		int nesting;
		int localClientNum[8];
		int controllerIndex[8];
		int argc[8];
		const char** argv[8];
	};

	struct cmd_function_s
	{
		cmd_function_s* next;
		const char* name;
		void(__fastcall* function)();
	};

	struct SvCommandInfo
	{
		const char* name;
		void(__fastcall* function)();
		cmd_function_s svvar;
	};

	enum DvarSetSource : std::uint32_t
	{
		DVAR_SOURCE_INTERNAL = 0x0,
		DVAR_SOURCE_EXTERNAL = 0x1,
		DVAR_SOURCE_SCRIPT = 0x2,
		DVAR_SOURCE_UISCRIPT = 0x3,
		DVAR_SOURCE_SERVERCMD = 0x4,
		DVAR_SOURCE_NUM = 0x5,
	};

	enum DvarFlags : std::uint32_t
	{
		DVAR_FLAG_NONE = 0,
		DVAR_FLAG_SAVED = 0x1,
		DVAR_FLAG_LATCHED = 0x2,
		DVAR_FLAG_CHEAT = 0x4,
		DVAR_FLAG_REPLICATED = 0x8,
		DVAR_FLAG_NETWORK = 0x10,
		DVAR_FLAG_EXTERNAL = 0x100,
		DVAR_FLAG_WRITE = 0x800,
		DVAR_FLAG_READ = 0x2000,
	};

	enum DvarType : std::uint8_t
	{
		DVAR_TYPE_BOOL = 0x0,
		DVAR_TYPE_FLOAT = 0x1,
		DVAR_TYPE_FLOAT_2 = 0x2,
		DVAR_TYPE_FLOAT_3 = 0x3,
		DVAR_TYPE_FLOAT_4 = 0x4,
		DVAR_TYPE_INT = 0x5,
		DVAR_TYPE_ENUM = 0x6,
		DVAR_TYPE_STRING = 0x7,
		DVAR_TYPE_COLOR = 0x8,
		DVAR_TYPE_FLOAT_3_COLOR = 0x9,
		DVAR_TYPE_COUNT = 0xA,

		boolean = 0,
		value = 1,
		vec2 = 2,
		vec3 = 3,
		vec4 = 4,
		integer = 5,
		enumeration = 6,
		string = 7,
		color = 8,
		rgb = 9, // Color without alpha
	};

	union DvarValue
	{
		bool enabled;
		int integer;
		unsigned int unsignedInt;
		float value;
		float vector[4];
		const char* string;
		char color[4];
	};

	struct $A37BA207B3DDD6345C554D4661813EDD
	{
		int stringCount;
		const char* const* strings;
	};

	struct $9CA192F9DB66A3CB7E01DE78A0DEA53D
	{
		int min;
		int max;
	};

	struct $251C2428A496074035CACA7AAF3D55BD
	{
		float min;
		float max;
	};

	union DvarLimits
	{
		$A37BA207B3DDD6345C554D4661813EDD enumeration;
		$9CA192F9DB66A3CB7E01DE78A0DEA53D integer;
		$251C2428A496074035CACA7AAF3D55BD value;
		$251C2428A496074035CACA7AAF3D55BD vector;
	};

	struct dvar_t
	{
		unsigned int checksum;
		unsigned int flags;
		char level;
		DvarType type;
		bool modified;
		DvarValue current;
		DvarValue latched;
		DvarValue reset;
		DvarLimits domain;
		bool(__fastcall* domainFunc)(dvar_t*, DvarValue);
		dvar_t* hashNext;
	}; static_assert(sizeof(dvar_t) == 96);

	enum svscmd_type
	{
		SV_CMD_CAN_IGNORE = 0x0,
		SV_CMD_RELIABLE = 0x1,
	};

	enum keyNum_t
	{
		K_NONE = 0x0,
		K_FIRSTGAMEPADBUTTON_RANGE_1 = 0x1,
		K_BUTTON_A = 0x1,
		K_BUTTON_B = 0x2,
		K_BUTTON_X = 0x3,
		K_BUTTON_Y = 0x4,
		K_BUTTON_LSHLDR = 0x5,
		K_BUTTON_RSHLDR = 0x6,
		K_LASTGAMEPADBUTTON_RANGE_1 = 0x6,
		K_BS = 0x8,
		K_TAB = 0x9,
		K_ENTER = 0xD,
		K_FIRSTGAMEPADBUTTON_RANGE_2 = 0xE,
		K_BUTTON_START = 0xE,
		K_BUTTON_BACK = 0xF,
		K_BUTTON_LSTICK = 0x10,
		K_BUTTON_RSTICK = 0x11,
		K_BUTTON_LTRIG = 0x12,
		K_BUTTON_RTRIG = 0x13,
		K_DPAD_UP = 0x14,
		K_FIRSTDPAD = 0x14,
		K_DPAD_DOWN = 0x15,
		K_DPAD_LEFT = 0x16,
		K_DPAD_RIGHT = 0x17,
		K_BUTTON_LSTICK_ALTIMAGE2 = 0x10,
		K_BUTTON_RSTICK_ALTIMAGE2 = 0x11,
		K_BUTTON_LSTICK_ALTIMAGE = 0xBC,
		K_BUTTON_RSTICK_ALTIMAGE = 0xBD,
		K_LASTDPAD = 0x17,
		K_LASTGAMEPADBUTTON_RANGE_2 = 0x17,
		K_ESCAPE = 0x1B,
		K_FIRSTGAMEPADBUTTON_RANGE_3 = 0x1C,
		K_APAD_UP = 0x1C,
		K_FIRSTAPAD = 0x1C,
		K_APAD_DOWN = 0x1D,
		K_APAD_LEFT = 0x1E,
		K_APAD_RIGHT = 0x1F,
		K_LASTAPAD = 0x1F,
		K_LASTGAMEPADBUTTON_RANGE_3 = 0x1F,
		K_SPACE = 0x20,
		K_GRAVE = 0x60,
		K_TILDE = 0x7E,
		K_BACKSPACE = 0x7F,
		K_ASCII_FIRST = 0x80,
		K_ASCII_181 = 0x80,
		K_ASCII_191 = 0x81,
		K_ASCII_223 = 0x82,
		K_ASCII_224 = 0x83,
		K_ASCII_225 = 0x84,
		K_ASCII_228 = 0x85,
		K_ASCII_229 = 0x86,
		K_ASCII_230 = 0x87,
		K_ASCII_231 = 0x88,
		K_ASCII_232 = 0x89,
		K_ASCII_233 = 0x8A,
		K_ASCII_236 = 0x8B,
		K_ASCII_241 = 0x8C,
		K_ASCII_242 = 0x8D,
		K_ASCII_243 = 0x8E,
		K_ASCII_246 = 0x8F,
		K_ASCII_248 = 0x90,
		K_ASCII_249 = 0x91,
		K_ASCII_250 = 0x92,
		K_ASCII_252 = 0x93,
		K_END_ASCII_CHARS = 0x94,
		K_COMMAND = 0x96,
		K_CAPSLOCK = 0x97,
		K_POWER = 0x98,
		K_PAUSE = 0x99,
		K_UPARROW = 0x9A,
		K_DOWNARROW = 0x9B,
		K_LEFTARROW = 0x9C,
		K_RIGHTARROW = 0x9D,
		K_ALT = 0x9E,
		K_CTRL = 0x9F,
		K_SHIFT = 0xA0,
		K_INS = 0xA1,
		K_DEL = 0xA2,
		K_PGDN = 0xA3,
		K_PGUP = 0xA4,
		K_HOME = 0xA5,
		K_END = 0xA6,
		K_F1 = 0xA7,
		K_F2 = 0xA8,
		K_F3 = 0xA9,
		K_F4 = 0xAA,
		K_F5 = 0xAB,
		K_F6 = 0xAC,
		K_F7 = 0xAD,
		K_F8 = 0xAE,
		K_F9 = 0xAF,
		K_F10 = 0xB0,
		K_F11 = 0xB1,
		K_F12 = 0xB2,
		K_F13 = 0xB3,
		K_F14 = 0xB4,
		K_F15 = 0xB5,
		K_KP_HOME = 0xB6,
		K_KP_UPARROW = 0xB7,
		K_KP_PGUP = 0xB8,
		K_KP_LEFTARROW = 0xB9,
		K_KP_5 = 0xBA,
		K_KP_RIGHTARROW = 0xBB,
		K_KP_END = 0xBC,
		K_KP_DOWNARROW = 0xBD,
		K_KP_PGDN = 0xBE,
		K_KP_ENTER = 0xBF,
		K_KP_INS = 0xC0,
		K_KP_DEL = 0xC1,
		K_KP_SLASH = 0xC2,
		K_KP_MINUS = 0xC3,
		K_KP_PLUS = 0xC4,
		K_KP_NUMLOCK = 0xC5,
		K_KP_STAR = 0xC6,
		K_KP_EQUALS = 0xC7,
		K_MOUSE1 = 0xC8,
		K_MOUSE2 = 0xC9,
		K_MOUSE3 = 0xCA,
		K_MOUSE4 = 0xCB,
		K_MOUSE5 = 0xCC,
		K_MWHEELDOWN = 0xCD,
		K_MWHEELUP = 0xCE,
		K_AUX1 = 0xCF,
		K_AUX2 = 0xD0,
		K_AUX3 = 0xD1,
		K_AUX4 = 0xD2,
		K_AUX5 = 0xD3,
		K_AUX6 = 0xD4,
		K_AUX7 = 0xD5,
		K_AUX8 = 0xD6,
		K_AUX9 = 0xD7,
		K_AUX10 = 0xD8,
		K_AUX11 = 0xD9,
		K_AUX12 = 0xDA,
		K_AUX13 = 0xDB,
		K_AUX14 = 0xDC,
		K_AUX15 = 0xDD,
		K_AUX16 = 0xDE,
		K_LAST_KEY = 0xDF
	};

	struct KeyState
	{
		int down;
		int unk;
		int repeats;
		int binding;
	};

	struct field_t
	{
		int cursor;
		int scroll;
		int drawWidth;
		int widthInPixels;
		float charHeight;
		int fixedSize;
		char buffer[256];
	};

	struct PlayerKeyState
	{
		int overstrikeMode;
		int anyKeyDown;
		KeyState keys[256];
		field_t chatField;
		char __pad0[8];
	}; static_assert(sizeof(PlayerKeyState) == 0x1128);

	struct ScreenPlacement
	{
		vec2_t scaleVirtualToReal;
		vec2_t scaleVirtualToFull;
		vec2_t scaleRealToVirtual;
		vec2_t realViewportPosition;
		vec2_t realViewportSize;
		vec2_t virtualViewableMin;
		vec2_t virtualViewableMax;
		vec2_t realViewableMin;
		vec2_t realViewableMax;
		vec2_t virtualAdjustableMin;
		vec2_t virtualAdjustableMax;
		vec2_t realAdjustableMin;
		vec2_t realAdjustableMax;
		vec2_t subScreenLeft;
	};

	enum netadrtype_t
	{
		NA_BOT = 0x0,
		NA_BAD = 0x1,
		NA_LOOPBACK = 0x2,
		NA_BROADCAST = 0x3,
		NA_IP = 0x4,
	};

	enum netsrc_t
	{
		NS_CLIENT1 = 0x0,
		NS_MAXCLIENTS = 0x1,
		NS_SERVER = 0x2,
		NS_PACKET = 0x3,
		NS_INVALID_NETSRC = 0x4,
	};

	struct netadr_s
	{
		netadrtype_t type;
		union
		{
			unsigned char ip[4];
			uint32_t addr;
		};
		unsigned __int16 port;
		netsrc_t localNetID;
		unsigned int addrHandleIndex;
	};

	struct msg_t
	{
		int overflowed;
		int readOnly;
		char* data;
		char* splitData;
		int maxsize;
		int cursize;
		int splitSize;
		int readcount;
		int bit;
		int lastEntityRef;
		netsrc_t targetLocalNetID;
		int useZlib;
	};

	enum CriticalSection : std::int32_t
	{
		CRITSECT_DEMONWARE = 39,
	};

	enum ThreadContext
	{
		THREAD_CONTEXT_MAIN = 0,
		THREAD_CONTEXT_BACKEND = 1,
		THREAD_CONTEXT_WORKER0 = 2,
		THREAD_CONTEXT_WORKER1 = 3,
		THREAD_CONTEXT_WORKER2 = 4,
		THREAD_CONTEXT_WORKER3 = 5,
		THREAD_CONTEXT_WORKER4 = 6,
		THREAD_CONTEXT_WORKER5 = 7,
		THREAD_CONTEXT_WORKER6 = 8,
		THREAD_CONTEXT_WORKER7 = 9,
		THREAD_CONTEXT_SERVER = 10,
		THREAD_CONTEXT_CINEMATIC = 11,
		THREAD_CONTEXT_WINDOW = 12,
		THREAD_CONTEXT_INPUT = 13,
		THREAD_CONTEXT_DATABASE = 14,
		THREAD_CONTEXT_SOUND_STREAM = 15,
		THREAD_CONTEXT_SOUND = 16,
		THREAD_CONTEXT_SOUND_DECODE = 17,
		THREAD_CONTEXT_UNKNOWN18 = 18, // server watcher?
		THREAD_CONTEXT_UNKNOWN19 = 19, // umbra
		THREAD_CONTEXT_RECIPE = 20,
	};

	enum StatsGroup
	{
		STATSGROUP_RANKED = 0x0,
		STATSGROUP_COOP = 0x1,
		STATSGROUP_COMMON = 0x2,
		STATSGROUP_RANKEDLOADOUTS = 0x3,
		STATSGROUP_PRIVATELOADOUTS = 0x4,
		//STATSGROUP_NONGAME = 0x5,
		STATSGROUP_COUNT = 0x5,
		STATSGROUP_IGNORE = 0x6,
		STATSGROUP_FIRST = 0x0,
	};

	// made up
	struct connection_data
	{
		char __pad0[131112];
		netadr_s address;
	};
	
	enum FontType
	{
		FONT_TYPE_BIG_FONT = 2,
		FONT_TYPE_SMALL_FONT = 3,
		FONT_TYPE_BOLD_FONT = 4,
		FONT_TYPE_CONSOLE_FONT = 5,
		FONT_TYPE_OBJECTIVE_FONT = 6,
		FONT_TYPE_TEXT_FONT = 7,
		FONT_TYPE_EXTRA_BIG_FONT = 8,
		FONT_TYPE_HUD_BIG_FONT = 9,
		FONT_TYPE_HUD_SMALL_FONT = 10,
	};

	struct GfxFont
	{
		const char* fontName;
		int pixelHeight;
		TTFDef* ttfDef;
	};

	enum GfxDrawSceneMethod
	{
		GFX_DRAW_SCENE_STANDARD = 0x1,
	};

	struct GfxDrawMethod
	{
		int drawScene;
		int baseTechType;
		int emissiveTechType;
		int forceTechType;
	};

	struct directory_t
	{
		char path[256];
		char gamedir[256];
	};

	struct searchpath_s
	{
		searchpath_s* next;
		directory_t* dir;
		int bLocalized;
		int playersFolder;
		int language;
		int pad;
	};

	enum PLAYERCARD_CACHE_TASK_STAGE
	{
		PLAYERCARD_CACHE_TASK_STAGE_WAITING = 0x0,
		PLAYERCARD_CACHE_TASK_STAGE_WORKING = 0x1,
		PLAYERCARD_CACHE_TASK_STAGE_ALL_DONE = 0x2,
	};

	struct CachedPlayerProfile
	{
		bool has_data;
		XUID userID;
		char profile[2201];
		int time;
	};

	struct XAnimParent
	{
		unsigned __int16 flags;
		unsigned __int16 children;
	};

	union $1A6660B292B883AB62F4E15A2C35B0BF
	{
		game::XAnimParts* parts;
		XAnimParent animParent;
	};

	struct XAnimEntry
	{
		char nodeType[1];
		char lod;
		unsigned __int16 numAnims;
		unsigned __int16 parent;
		unsigned __int16 bindingIndex;
		$1A6660B292B883AB62F4E15A2C35B0BF ___u2;
	};

	struct XAnim_s
	{
		unsigned int size;
		bool initialized;
		bool dirtyBindings;
		unsigned __int16 numGameParameters;
		unsigned __int16 maxGameParameters;
		unsigned __int16 numBindings;
		unsigned __int16 maxBindings;
		const void** gameParameterNames;
		void* bindings;
		XAnimEntry entries[1];
	};

	enum SayModes
	{
		SAY_ALL = 0x0,
		SAY_TEAM = 0x1,
		SAY_TELL = 0x2,
	};

	enum ConfigString : std::int32_t
	{
		CS_TIMESCALE = 3464,
	};

	enum FontStyle
	{
		FONT_STYLE_NONE = 0,
		FONT_STYLE_SHADOW = 3,
		FONT_STYLE_STRONG_SHADOW = 6,
		FONT_STYLE_OUTLINE = 7,
		FONT_STYLE_STRONG_OUTLINE = 8,
	};

	struct FontGlowStyle
	{
		float glowMinDistance;
		float glowMaxDistance;
		vec2_t glowUVOffset;
		vec4_t glowColor;
		float outlineGlowMinDistance;
		float outlineGlowMaxDistance;
		vec4_t outlineGlowColor;
	};

	struct ComGameStartupData
	{
		int state;
		char mapname[64];
		char gameType[64];
		unsigned int loadTime;
		bool isServer;
	};

	struct rectDef_s
	{
		float x;
		float y;
		float w;
		float h;
		char horzAlign;
		char vertAlign;
	};

	namespace entity
	{
		enum connstate_t : std::uint32_t
		{
			CA_DISCONNECTED = 0x0,
			CA_CONNECTING = 0x1,
			CA_CHALLENGING = 0x2,
			CA_CONNECTED = 0x3,
			CA_SENDINGSTATS = 0x4,
			CA_REQUESTING_MATCH_RULES = 0x5,
			CA_STARTING = 0x6,
			CA_LOADING = 0x7,
			CA_PRIMED = 0x8,
			CA_ACTIVE = 0x9,
			CA_MAP_RESTART = 0xA,
		};

		struct uiClientState_t
		{
			connstate_t connState;
			int connectPacketCount;
			char servername[1024];
			char messageString[1024];
		};

		struct clientUIActive_t
		{
			bool active;
			bool isRunning;
			int keyCatchers;
			connstate_t connectionState;
			char __pad0[20];
			BYTE frontEndSceneState[1];
			bool cgameInitialized;
			bool cgameInitCalled;
			char __pad1[161];
		}; static_assert(sizeof(clientUIActive_t) == 196);
		static_assert(offsetof(clientUIActive_t, connectionState) == 8);
		static_assert(offsetof(clientUIActive_t, frontEndSceneState) == 32);
		static_assert(offsetof(clientUIActive_t, cgameInitialized) == 33);

		struct entityState_t
		{
			__int16 number; // 0
			char __pad0[150];
			int surfType;
			int clientNum;
		}; // sizeof = ?

		assert_offsetof(entityState_t, clientNum, 156);

		enum weaponstate_t : std::int32_t
		{
			WEAPON_READY = 0,
			WEAPON_RAISING = 1,
			WEAPON_RAISING_ALTSWITCH = 2,
			WEAPON_RAISING_ALTSWITCH_ADS = 3,

			WEAPON_FIRING = 0x10,
			WEAPON_RECHAMBERING = 0x11,
		};

		enum WeaponAnimNumber : std::int32_t
		{
			WEAP_IDLE = 0,
			WEAP_FORCE_IDLE = 1,
			WEAP_ATTACK = 2,
			WEAP_ATTACK_LASTSHOT = 3,
			WEAP_RECHAMBER = 4,
			WEAP_ADS_ATTACK = 5,
			WEAP_ADS_ATTACK_LASTSHOT = 6,
			WEAP_ADS_RECHAMBER = 7,
			WEAP_GRENADE_PRIME = 8,
			WEAP_GRENADE_PRIME_READY_TO_THROW = 9,
			WEAP_MELEE_SWIPE = 10,
			WEAP_MELEE_HIT = 11,
			WEAP_MELEE_FATAL = 12,
			WEAP_MELEE_MISS = 13,
			WEAP_MELEE_VICTIM_CROUCHING_HIT = 14,
			WEAP_MELEE_VICTIM_CROUCHING_FATAL = 15,
			WEAP_MELEE_VICTIM_CROUCHING_MISS = 16,
			WEAP_DROP = 17,
			WEAP_RAISE = 18,
			WEAP_FIRST_RAISE = 19,
			WEAP_RELOAD = 20,
			WEAP_RELOAD_EMPTY = 21,
			WEAP_RELOAD_START = 22,
			WEAP_RELOAD_END = 23,
			WEAP_ALTSWITCHFROM = 24,
			WEAP_ALTSWITCHFROM_ADS = 25,
			WEAP_ALTSWITCHFROM_AKIMBO = 26,
			WEAP_ALTSWITCHTO = 27,
			WEAP_ALTSWITCHTO_ADS = 28,
			WEAP_ALTSWITCHTO_AKIMBO = 29,
			WEAP_QUICK_DROP = 30,
			WEAP_QUICK_RAISE = 31,
			WEAP_EMPTY_DROP = 32,
			WEAP_EMPTY_RAISE = 33,
			WEAP_SPRINT_IN = 34,
			WEAP_SPRINT_IN_CANCEL = 35,
			WEAP_SPRINT_LOOP = 36,
			WEAP_SPRINT_OUT = 37,
			WEAP_STUNNED_START = 38,
			WEAP_STUNNED_LOOP = 39,
			WEAP_STUNNED_END = 40,
			WEAP_HOLD_FIRE = 41,
			WEAP_DETONATE = 42,
			WEAP_NIGHTVISION_WEAR = 43,
			WEAP_NIGHTVISION_REMOVE = 44,
			WEAP_BLAST_IMPACT_FRONT = 45,
			WEAP_BLAST_IMPACT_LEFT = 46,
			WEAP_BLAST_IMPACT_BACK = 47,
			WEAP_BLAST_IMPACT_RIGHT = 48,
			WEAP_SLIDE = 49,
			WEAP_SWIM_LOOP = 50,
			WEAP_DODGE = 51,
			WEAP_LEAP_IN = 52,
			WEAP_LEAP_LOOP = 53,
			WEAP_LEAP_OUT = 54,
			WEAP_LEAP_CANCEL = 55,
			WEAP_CHARGE_INT = 56,
			WEAP_CHARGE_LOOP = 57,
			WEAP_CHARGE_OUT = 58,
			WEAP_ADS_CHARGE_INT = 59,
			WEAP_ADS_CHARGE_LOOP = 60,
			WEAP_ADS_CHARGE_OUT = 61,
			WEAP_WALLRUN = 62,
			WEAP_INSPECT = 100, // custom added
		};

		struct PlayerActiveWeaponState
		{
			int weapAnim;
			int weaponTime;
			int weaponDelay;
			int weaponRestrictKickTime;
			int weaponState;
			char __pad0[32];
		}; 
		assert_sizeof(PlayerActiveWeaponState, 52);
		assert_offsetof(PlayerActiveWeaponState, weapAnim, 0);
		assert_offsetof(PlayerActiveWeaponState, weaponTime, 4);
		assert_offsetof(PlayerActiveWeaponState, weaponDelay, 8);
		assert_offsetof(PlayerActiveWeaponState, weaponState, 16);

		enum pmtype_t : std::int32_t
		{
			PM_NORMAL = 0x0,
			PM_NORMAL_LINKED = 0x1,
			PM_NOCLIP = 0x2,
			PM_UFO = 0x3,
			PM_MPVIEWER = 0x4,
			PM_SPECTATOR = 0x5,
			PM_INTERMISSION = 0x6,
			PM_DEAD = 0x7,
			PM_DEAD_LINKED = 0x8,
		};

		enum PMoveFlagsCommon : std::uint64_t;
		enum PMoveFlagsSP : std::uint64_t;
		enum PMoveFlagsMP : std::uint64_t;

		enum POtherFlagsCommon : std::uint64_t;
		enum POtherFlagsSP : std::uint64_t;
		enum POtherFlagsMP : std::uint64_t;

		enum PLinkFlagsCommon : std::uint32_t;
		enum PLinkFlagsSP : std::uint32_t;
		enum PLinkFlagsMP : std::uint32_t;

		enum EntityStateFlagsCommon : std::uint32_t;
		enum EntityStateFlagsSP : std::uint32_t;
		enum EntityStateFlagsMP : std::uint32_t;

		enum PWeaponFlagsCommon : std::uint64_t;
		enum PWeaponFlagsSP : std::uint64_t;
		enum PWeaponFlagsMP : std::uint64_t;

		template<typename CommonE, typename spE, typename mpE, int bitSize>
		struct GameModeFlagContainer
		{
			static_assert(bitSize % sizeof(unsigned int) * CHAR_BIT == 0, "bitSize must be divisible by sizeof(unsigned int) * CHAR_BIT");
			unsigned int m_flags[bitSize >> (sizeof(unsigned int) + 1)];
		};

		struct PlayerWeaponCommonState
		{
			unsigned __int16 weaponIdx;
		};

		struct playerState_s
		{
			int commandTime;
			int pm_type;
			int pm_time;
			GameModeFlagContainer<PMoveFlagsCommon, PMoveFlagsSP, PMoveFlagsMP, 64> pm_flags;
			GameModeFlagContainer<POtherFlagsCommon, POtherFlagsSP, POtherFlagsMP, 64> otherFlags;
			GameModeFlagContainer<PLinkFlagsCommon, PLinkFlagsSP, PLinkFlagsMP, 32> linkFlags;
			int packedBobCycle[2];
			vec3_t origin;
			vec3_t velocity;
			char __pad0[68];
			vec3_t delta_angles;
			char __pad1[200];
			GameModeFlagContainer<EntityStateFlagsCommon, EntityStateFlagsSP, EntityStateFlagsMP, 32> eFlags;
			char __pad2[92];
			vec3_t viewangles;
			char __pad3[1168];
			PlayerActiveWeaponState weapState[2];
			char __pad4[464];
			GameModeFlagContainer<PWeaponFlagsCommon, PWeaponFlagsSP, PWeaponFlagsMP, 64> weapFlags;
			float fWeaponPosFrac;
			char __pad5[0x4000];
		}; // unk size
		assert_offsetof(playerState_s, pm_type, 4);
		assert_offsetof(playerState_s, delta_angles, 132);
		assert_offsetof(playerState_s, eFlags, 344);
		assert_offsetof(playerState_s, viewangles, 440);
		assert_offsetof(playerState_s, weapState, 1620);
		assert_offsetof(playerState_s, weapFlags, 2188);

		struct usercmd_s
		{
			unsigned __int64 buttons;
			char __pad0[112];
		}; assert_sizeof(usercmd_s, 120);

		struct pmove_t
		{
			void* unk;
			playerState_s* ps;
			usercmd_s cmd;
			usercmd_s oldcmd;
			char __pad0[312];
			void* weaponMap;
			unsigned char handler;
		};
		assert_offsetof(pmove_t, handler, 576);
		assert_offsetof(pmove_t, weaponMap, 568);

		struct pml_t
		{
			float forward[3];
			float right[3];
			float up[3];
			float frametime;
			int msec;
			int walking;
			int groundPlane;
			int almostGroundPlane;
			int groundTrace;
			float impactSpeed;
			float previous_origin[3];
			float previous_velocity[3];
			float wishdir[3];
			unsigned int holdrand;
		};
		assert_offsetof(pml_t, msec, 40);

		enum clientConnected_t
		{
			CON_DISCONNECTED = 0x0,
			CON_CONNECTING = 0x1,
			CON_CONNECTED = 0x2,
		};

		enum sessionState_t
		{
			SESS_STATE_PLAYING = 0x0,
			SESS_STATE_DEAD = 0x1,
			SESS_STATE_SPECTATOR = 0x2,
			SESS_STATE_INTERMISSION = 0x3,
		};

		enum team_t : std::int32_t
		{
			TEAM_FREE = 0x0,
			TEAM_BAD = 0x0,
			TEAM_AXIS = 0x1,
			TEAM_ALLIES = 0x2,
			TEAM_SPECTATOR = 0x3,
			TEAM_NUM_TEAMS = 0x4,
		};

		struct clientState_s
		{
			int clientIndex;
			team_t team;
			char __pad0[108];
			char name[32];
		};

		struct clientSession_t
		{
			clientConnected_t connected;
			sessionState_t sessionState;
			char __pad0[280];
			char name[32];
			char __pad1[12];
			clientState_s cs;
		}; // unk size

		struct gclient_s
		{
			playerState_s ps;
			char __pad0[19088 - sizeof(playerState_s)];
			clientSession_t sess; // 19088
			char __pad1[20924 - sizeof(clientSession_t) - 19088];
			int flags; // 20924
		}; // sizeof = 29208?

		assert_offsetof(gclient_s, sess.sessionState, 19092);
		assert_offsetof(gclient_s, sess.name, 19376);

		assert_offsetof(gclient_s, sess.cs, 19420);
		assert_offsetof(gclient_s, sess.cs.team, 19424);
		assert_offsetof(gclient_s, sess.cs.name, 19536);

		static_assert(offsetof(gclient_s, flags) == 20924);

#pragma pack(push, 1)
		struct gentity_s
		{
			entityState_t s; // 0
			char __pad0[368 - sizeof(entityState_t)];
			gclient_s* client; // 368
			void* turret;
			void* agent;
			void* sentient;
			void* vehicle;
			__int64 physObjId;
			unsigned __int16 model;
			unsigned __int8 physicsObject;
			unsigned __int8 takedamage;
			unsigned __int8 active;
			unsigned __int8 handler;
			unsigned __int8 team;
			bool freeAfterEvent;
			unsigned __int16 disconnectedLinks;
			__int16 padding_short2;
			scr_string_t classname;
			scr_string_t script_classname;
			scr_string_t script_linkName;
			scr_string_t target;
			scr_string_t targetname;
			unsigned int attachIgnoreCollision;
			int spawnflags;
			int flags; // 456
			char __pad3[556];
		}; static_assert(sizeof(gentity_s) == 1016);
#pragma pack(pop)

		static_assert(offsetof(gentity_s, client) == 368);
		static_assert(offsetof(gentity_s, flags) == 456);

		enum SvClientConnectionState
		{
			CS_FREE = 0x0,
			CS_ZOMBIE = 0x1,
			CS_RECONNECTING = 0x2,
			CS_CONNECTED = 0x3,
			CS_CLIENTLOADING = 0x4,
			CS_ACTIVE = 0x5,
		};

		struct clientHeader_t
		{
			void* unk; // 0
			int state; // 8
		}; // sizeof = ?

		struct client_t
		{
			clientHeader_t header; // 0
			char __pad0[120]; // 16
			gentity_s* gentity; // 136
			char __pad1[20];
			char userinfo[1024];
			char name[32]; // 1188
			char __pad2[648396]; // 1220
			netadr_s remoteAddress; // 649616
			char __pad5[2460]; // 649636
			char playerGuid[21]; // 652096
			char __pad6[63299]; // 652117
		}; static_assert(sizeof(client_t) == 715416);
		
		static_assert(offsetof(client_t, header.state) == 8);
		static_assert(offsetof(client_t, gentity) == 136);
		static_assert(offsetof(client_t, userinfo) == 164);
		static_assert(offsetof(client_t, name) == 1188);
		static_assert(offsetof(client_t, remoteAddress) == 649616);
		static_assert(offsetof(client_t, playerGuid) == 652096);
	}
	using namespace entity;

	enum CubemapShot
	{
		CUBEMAPSHOT_NONE = 0x0,
		CUBEMAPSHOT_RIGHT = 0x1,
		CUBEMAPSHOT_LEFT = 0x2,
		CUBEMAPSHOT_BACK = 0x3,
		CUBEMAPSHOT_FRONT = 0x4,
		CUBEMAPSHOT_UP = 0x5,
		CUBEMAPSHOT_DOWN = 0x6,
		CUBEMAPSHOT_COUNT = 0x7,
	};

	struct cg_s
	{
		void* dummy;
		playerState_s predictedPlayerState;
		char __pad0[19160 - sizeof(playerState_s) - 8];
		CubemapShot cubemapShot;
		int cubemapSize;
		char __pad1[305200];
		float viewModelAxis[4][3];
		char __pad2[168476];
		int renderScreen;
		int latestSnapshotNum;
		int latestSnapshotTime;
		int mapRestart;
		int spectatingThirdPerson;
		int renderingThirdPerson;
		char __pad3[60792];
		bool m_deathCameraFailsafeLock;
		char __pad4[3];
		char __pad5[486328];
	}; static_assert(sizeof(cg_s) == 1040040);
	static_assert(offsetof(cg_s, cubemapShot) == 19160);
	static_assert(offsetof(cg_s, cubemapSize) == 19164);
	static_assert(offsetof(cg_s, viewModelAxis) == 324368);
	static_assert(offsetof(cg_s, renderScreen) == 492892);
	static_assert(offsetof(cg_s, spectatingThirdPerson) == 492908);
	static_assert(offsetof(cg_s, renderingThirdPerson) == 492912);
	static_assert(offsetof(cg_s, m_deathCameraFailsafeLock) == 553708);

	struct GfxLight
	{
		unsigned __int8 type;
		unsigned __int8 canUseShadowMap;
		unsigned __int8 needsDynamicShadows;
		unsigned __int8 isVolumetric;
		unsigned __int8 exponent;
		float uvIntensity;
		float irIntensity;
		float color[3];
		float dir[3];
		float up[3];
		float origin[3];
		float radius;
		vec2_t fadeOffsetRt;
		float bulbRadius;
		vec3_t bulbLength;
		float cosHalfFovOuter;
		float cosHalfFovInner;
		unsigned int entityId;
		unsigned int flags;
		float tonemappingScaleFactor;
		float shadowSoftness;
		float shadowBias;
		float shadowArea;
		float distanceFalloff;
		GfxLightDef* def;
	};

	struct GfxDynamicLight
	{
		GfxLight light;
		float nearPlaneOffset;
		float radius;
		char __pad0[144];
	};

	struct GfxScaledPlacement
	{
		GfxPlacement base;
		float scale;
	};

	struct GfxSceneModel
	{
		XModelDrawInfo info;
		const XModel* model;
		const struct DObj* obj;
		GfxScaledPlacement placement;
		GfxScaledPlacement prevPlacement;
		unsigned __int32 gfxEntIndex : 7;
		unsigned __int32 entnum : 12;
		unsigned __int32 renderFlags : 14;
		float radius;
		unsigned __int16* cachedLightingHandle;
		vec3_t lightingOrigin;
		int unk1;
		float unk2;
		int unk3;
		int unk4;
		int unk5;
	};

	union GfxDrawGroupSetup
	{
		unsigned __int64 packed;
	};

	struct GfxCodeSurf
	{
		GfxDrawGroupSetup drawGroup;
		unsigned int triCount;
		unsigned int vertIndexBase;
		unsigned __int16* indices;
		unsigned __int16 argOffset;
		unsigned __int16 argCount;
		int reactiveTurbulenceGroup;
		int sortOrder;
		int unk;
	};

	struct GfxSceneEntity
	{
		char __pad0[1424];
	};

	struct GfxScene
	{
		GfxCodeSurf codeEmissiveSurfs[16384];
		GfxCodeSurf surfs2[640];
		GfxCodeSurf surfs3[1424];
		GfxCodeSurf surfs4[640];
		GfxCodeSurf surfs5[640];
		char __pad0[2461208];
		unsigned int codeEmissiveSurfCount;
		unsigned int surfs2Count;
		unsigned int surfs3Count;
		unsigned int surfs4Count;
		unsigned int surfs5Count;
		char __pad1[64];
		volatile int dynamicSpotLightCount;
		GfxDynamicLight dynamicSpotLight[64];
		char __pad2[1129016];
		GfxSceneEntity sceneDObj[512];
		char sceneDObjVisData[12][512];
		int sceneDObjMarkableViewmodelIndex;
		unsigned int sceneDObjFirstViewmodelIndex;
		unsigned int sceneDObjViewmodelCount;
		volatile int sceneModelCount;
		int sceneModelCountAtMark;
		int sceneDObjModelCount;
		GfxSceneModel sceneModel[1024];
		char sceneModelVisData[12][1024];
		char __pad3[16384];
	};

	assert_offsetof(GfxScene, sceneDObjViewmodelCount, 5133104);

	namespace scripting
	{
		enum VariableType
		{
			VAR_UNDEFINED = 0x0,
			VAR_BEGIN_REF = 0x1,
			VAR_POINTER = 0x1,
			VAR_STRING = 0x2,
			VAR_ISTRING = 0x3,
			VAR_VECTOR = 0x4,
			VAR_END_REF = 0x5,
			VAR_FLOAT = 0x5,
			VAR_INTEGER = 0x6,
			VAR_CODEPOS = 0x7,
			VAR_PRECODEPOS = 0x8,
			VAR_FUNCTION = 0x9,
			VAR_BUILTIN_FUNCTION = 0xA,
			VAR_BUILTIN_METHOD = 0xB,
			VAR_STACK = 0xC,
			VAR_ANIMATION = 0xD,
			VAR_PRE_ANIMATION = 0xE,
			VAR_THREAD = 0xF,
			VAR_NOTIFY_THREAD = 0x10,
			VAR_TIME_THREAD = 0x11,
			VAR_CHILD_THREAD = 0x12,
			VAR_OBJECT = 0x13,
			VAR_DEAD_ENTITY = 0x14,
			VAR_ENTITY = 0x15,
			VAR_ARRAY = 0x16,
			VAR_DEAD_THREAD = 0x17,
			VAR_COUNT = 0x18,
			VAR_FREE = 0x18,
			VAR_THREAD_LIST = 0x19,
			VAR_ENDON_LIST = 0x1A,
			VAR_TOTAL_COUNT = 0x1B,
		};

		struct scr_entref_t
		{
			unsigned short entnum;
			unsigned short classnum;
		};

		struct VariableStackBuffer
		{
			const char* pos;
			unsigned __int16 size;
			unsigned __int16 bufLen;
			unsigned __int16 localId;
			char time;
			char buf[1];
		};

		union VariableUnion
		{
			int intValue;
			unsigned int uintValue;
			float floatValue;
			unsigned int stringValue;
			const float* vectorValue;
			const char* codePosValue;
			unsigned int pointerValue;
			VariableStackBuffer* stackValue;
			unsigned int entityOffset;
		};

		struct VariableValue
		{
			VariableUnion u;
			int type;
		};

		struct function_stack_t
		{
			const char* pos;
			unsigned int localId;
			unsigned int localVarCount;
			VariableValue* top;
			VariableValue* startTop;
		};

		struct function_frame_t
		{
			function_stack_t fs;
			int topType;
		};

		struct scrVmPub_t
		{
			unsigned int* localVars;
			VariableValue* maxstack;
			int function_count;
			function_frame_t* function_frame;
			VariableValue* top;
			unsigned int inparamcount;
			unsigned int outparamcount;
			function_frame_t function_frame_start[32];
			VariableValue stack[2048];
		};

		struct ObjectVariableChildren
		{
			unsigned __int16 firstChild;
			unsigned __int16 lastChild;
		};

		struct ObjectVariableValue_u_f
		{
			unsigned __int16 prev;
			unsigned __int16 next;
		};

		union ObjectVariableValue_u_o_u
		{
			unsigned __int16 size;
			unsigned __int16 entnum;
			unsigned __int16 nextEntId;
			unsigned __int16 self;
		};

		struct	ObjectVariableValue_u_o
		{
			unsigned __int16 refCount;
			ObjectVariableValue_u_o_u u;
		};

		union ObjectVariableValue_w
		{
			unsigned int type;
			unsigned int classnum;
			unsigned int notifyName;
			unsigned int waitTime;
			unsigned int parentLocalId;
		};

		struct ChildVariableValue_u_f
		{
			unsigned __int16 prev;
			unsigned __int16 next;
		};

		union ChildVariableValue_u
		{
			ChildVariableValue_u_f f;
			VariableUnion u;
		};

		struct ChildBucketMatchKeys_keys
		{
			unsigned __int16 name_hi;
			unsigned __int16 parentId;
		};

		union ChildBucketMatchKeys
		{
			ChildBucketMatchKeys_keys keys;
			unsigned int match;
		};

		struct ChildVariableValue
		{
			ChildVariableValue_u u;
			unsigned __int16 next;
			char type;
			char name_lo;
			ChildBucketMatchKeys k;
			unsigned __int16 nextSibling;
			unsigned __int16 prevSibling;
		};

		union ObjectVariableValue_u
		{
			ObjectVariableValue_u_f f;
			ObjectVariableValue_u_o o;
		};

		struct ObjectVariableValue
		{
			ObjectVariableValue_u u;
			ObjectVariableValue_w w;
		};

		struct scrVarGlob_t
		{
			ObjectVariableValue objectVariableValue[40960];
			ObjectVariableChildren objectVariableChildren[40960];
			unsigned __int16 childVariableBucket[65536];
			ChildVariableValue childVariableValue[384000];
		};
	}
	using namespace scripting;

	namespace ddl
	{
		union DDLValue
		{
			int intValue;
			unsigned int uintValue;
			unsigned __int64 uint64Value;
			float floatValue;
			float fixedPointValue;
			const char* stringPtr;
		};

		struct DDLState
		{
			bool isValid;
			int offset;
			int arrayIndex;
			DDLMember* member;
			const DDLDef* ddlDef;
		};

		struct DDLContext
		{

		};
	}
	using namespace ddl;

	namespace session
	{
		struct SessionStaticData
		{
			const char* sessionName;
			bool registerUsersWithVoice;
		};

		struct ClientInfo
		{
			bool registered;
			bool voiceRegistered;
			unsigned __int64 xuid;
			int natType;
			netadr_s addr;
			int usrVoiceConnectivityBits;
			int nextConnectivityTestTime[1];
			bool muted;
			bool privateSlot;
		};

		struct RegisteredUser
		{
			bool active;
			unsigned __int64 xuid;
			bool privateSlot;
		};

		struct SessionDynamicData
		{
			bool sessionHandle;
			char __pad0[47];
			bool keysGenerated;
			bool sessionStartCalled;
			unsigned __int64 sessionNonce;
			int privateSlots;
			int publicSlots;
			int flags;
			bool qosListenEnabled;
			ClientInfo users[18];
			int localVoiceConnectivityBits;
			int sessionCreateController;
			int sessionDeleteTime;
			bool allowJoining;
			RegisteredUser internalRegisteredUsers[18];
		};

		struct SessionData
		{
			SessionStaticData staticData;
			SessionDynamicData dyn;
		};

		assert_sizeof(SessionData, 1552);
		assert_offsetof(SessionData, dyn.users, 96);
		assert_offsetof(SessionData, dyn.internalRegisteredUsers, 1120);
	}
	using namespace session;

	namespace party
	{
		enum PartyPreloadMapStage : std::uint32_t
		{
			PRELOAD_MAP_IDLE = 0x0,
			PRELOAD_MAP_INITIATED = 0x1,
			PRELOAD_MAP_STARTED = 0x2,
			PRELOAD_MAP_COUNT = 0x3,
		};

		struct PartyData
		{
			SessionData* session;
			char __pad0[11436];
			PartyPreloadMapStage preloadingMapStage;
			char __pad1[101];
			bool m_gameStartSkipCountdown;
			char __pad2[110];
			int lobbyFlags;
			bool gameStartRequested;
		};
		static_assert(offsetof(PartyData, preloadingMapStage) == 11444);
		static_assert(offsetof(PartyData, m_gameStartSkipCountdown) == 11549);
		static_assert(offsetof(PartyData, lobbyFlags) == 11660);
		static_assert(offsetof(PartyData, gameStartRequested) == 11664);
	}
	using namespace party;

	namespace sv
	{
		struct SvServerInitSettings
		{
			char mapName[64];
			char gameType[64];
			char serverHostName[64];
			bool hardcoreMode;
			unsigned int maxClientCount;
			unsigned int maxAgentCount;
			bool isMapPreloaded;
			bool isSaveGame;
			bool isRestart;
			bool isFrontEnd;
			char __pad0[2];
			bool serverThreadStartup;
		}; //static_assert(sizeof(SvServerInitSettings) == 212);
		static_assert(offsetof(SvServerInitSettings, maxClientCount) == 196);
		static_assert(offsetof(SvServerInitSettings, isMapPreloaded) == 204);
		static_assert(offsetof(SvServerInitSettings, isFrontEnd) == 207);
		static_assert(offsetof(SvServerInitSettings, serverThreadStartup) == 210);
	}
	using namespace sv;

	namespace pmem
	{
		enum PMem_Stack : __int32
		{
			PMEM_STACK_GAME = 0x0,
			PMEM_STACK_RENDER_TARGETS = 0x1,
			PMEM_STACK_MEM_VIRTUAL = 0x2,
			PMEM_STACK_MEMCARD_LARGE_BUFFER = 0x3,
			PMEM_STACK_SOUND = 0x4,
			PMEM_STACK_STASHED_MEMORY = 0x5,
			PMEM_STACK_CINEMATIC = 0x6,
			PMEM_STACK_COUNT = 0x7,
		};

		enum PMem_Source
		{
			PMEM_SOURCE_EXTERNAL = 0x0,
			PMEM_SOURCE_SCRIPT = 0x1,
		};

		enum PMem_Direction : __int32
		{
			PHYS_ALLOC_LOW = 0x0,
			PHYS_ALLOC_HIGH = 0x1,
			PHYS_ALLOC_COUNT = 0x2,
		};

		enum Mem_PageID
		{
		};

		struct Mem_PageRange
		{
			Mem_PageID firstPageID;
			Mem_PageID lastPageID;
		};

		struct PhysicalMemoryAllocation
		{
			const char* name;
			char* prev_buffer;
			char* next_buffer;
			unsigned __int64 pos;
			Mem_PageRange pageRange;
		};

		struct PhysicalMemoryPrim
		{
			const char* name;
			unsigned int allocListCount;
			char __pad0[4];
			unsigned __int8* buf;
			unsigned __int64 unk_pos;
			int unk1;
			char __pad2[4];
			unsigned __int64 pos;
			PhysicalMemoryAllocation allocList[32];
		};

		struct PhysicalMemory
		{
			PhysicalMemoryPrim prim[2];
		};
	}
	using namespace pmem;

	namespace hks
	{
		struct lua_State;
		struct HashTable;
		struct cclosure;

		struct GenericChunkHeader
		{
			unsigned __int64 m_flags;
		};

		struct ChunkHeader : GenericChunkHeader
		{
			ChunkHeader* m_next;
		};

		struct UserData : ChunkHeader
		{
			unsigned __int64 m_envAndSizeOffsetHighBits;
			unsigned __int64 m_metaAndSizeOffsetLowBits;
			char m_data[8];
		};

		struct InternString
		{
			unsigned __int64 m_flags;
			unsigned __int64 m_lengthbits;
			unsigned int m_hash;
			char m_data[30];
		};

		union HksValue
		{
			cclosure* cClosure;
			void* closure;
			UserData* userData;
			HashTable* table;
			void* tstruct;
			InternString* str;
			void* thread;
			void* ptr;
			float number;
			long long i64;
			unsigned long long ui64;
			unsigned int native;
			bool boolean;
		};

		enum HksObjectType
		{
			TANY = 0xFFFFFFFE,
			TNONE = 0xFFFFFFFF,
			TNIL = 0x0,
			TBOOLEAN = 0x1,
			TLIGHTUSERDATA = 0x2,
			TNUMBER = 0x3,
			TSTRING = 0x4,
			TTABLE = 0x5,
			TFUNCTION = 0x6,  // idk
			TUSERDATA = 0x7,
			TTHREAD = 0x8,
			TIFUNCTION = 0x9, // Lua function
			TCFUNCTION = 0xA, // C function
			TUI64 = 0xB,
			TSTRUCT = 0xC,
			NUM_TYPE_OBJECTS = 0xE,
		};

		struct HksObject
		{
			HksObjectType t;
			HksValue v;
		};

		const struct hksInstruction
		{
			unsigned int code;
		};

		struct ActivationRecord
		{
			HksObject* m_base;
			const hksInstruction* m_returnAddress;
			__int16 m_tailCallDepth;
			__int16 m_numVarargs;
			int m_numExpectedReturns;
		};

		struct CallStack
		{
			ActivationRecord* m_records;
			ActivationRecord* m_lastrecord;
			ActivationRecord* m_current;
			const hksInstruction* m_current_lua_pc;
			const hksInstruction* m_hook_return_addr;
			int m_hook_level;
		};

		struct ApiStack
		{
			HksObject* top;
			HksObject* base;
			HksObject* alloc_top;
			HksObject* bottom;
		};

		struct UpValue : ChunkHeader
		{
			HksObject m_storage;
			HksObject* loc;
			UpValue* m_next;
		};

		struct CallSite
		{
			_SETJMP_FLOAT128 m_jumpBuffer[16];
			CallSite* m_prev;
		};

		enum Status
		{
			NEW = 0x1,
			RUNNING = 0x2,
			YIELDED = 0x3,
			DEAD_ERROR = 0x4,
		};

		enum HksError
		{
			HKS_NO_ERROR = 0x0,
			HKS_ERRSYNTAX = 0xFFFFFFFC,
			HKS_ERRFILE = 0xFFFFFFFB,
			HKS_ERRRUN = 0xFFFFFF9C,
			HKS_ERRMEM = 0xFFFFFF38,
			HKS_ERRERR = 0xFFFFFED4,
			HKS_THROWING_ERROR = 0xFFFFFE0C,
			HKS_GC_YIELD = 0x1,
		};

		struct lua_Debug
		{
			int event;
			const char* name;
			const char* namewhat;
			const char* what;
			const char* source;
			int currentline;
			int nups;
			int nparams;
			int ishksfunc;
			int linedefined;
			int lastlinedefined;
			char short_src[512];
			int callstack_level;
			int is_tail_call;
		};

		using lua_function = int(__fastcall*)(lua_State*);

		struct luaL_Reg
		{
			const char* name;
			lua_function function;
		};

		struct Node
		{
			HksObject m_key;
			HksObject m_value;
		};

		struct Metatable
		{
		};

		struct HashTable : ChunkHeader
		{
			Metatable* m_meta;
			unsigned int m_version;
			unsigned int m_mask;
			Node* m_hashPart;
			HksObject* m_arrayPart;
			unsigned int m_arraySize;
			Node* m_freeNode;
		};

		struct cclosure : ChunkHeader
		{
			lua_function m_function;
			HashTable* m_env;
			__int16 m_numUpvalues;
			__int16 m_flags;
			InternString* m_name;
			HksObject m_upvalues[1];
		};

		enum HksCompilerSettings_BytecodeSharingFormat
		{
			BYTECODE_DEFAULT = 0x0,
			BYTECODE_INPLACE = 0x1,
			BYTECODE_REFERENCED = 0x2,
		};

		enum HksCompilerSettings_IntLiteralOptions
		{
			INT_LITERALS_NONE = 0x0,
			INT_LITERALS_LUD = 0x1,
			INT_LITERALS_32BIT = 0x1,
			INT_LITERALS_UI64 = 0x2,
			INT_LITERALS_64BIT = 0x2,
			INT_LITERALS_ALL = 0x3,
		};

		struct HksCompilerSettings
		{
			int m_emitStructCode;
			const char** m_stripNames;
			int m_emitGlobalMemoization;
			int _m_isHksGlobalMemoTestingMode;
			HksCompilerSettings_BytecodeSharingFormat m_bytecodeSharingFormat;
			HksCompilerSettings_IntLiteralOptions m_enableIntLiterals;
			int(__fastcall* m_debugMap)(const char*, int);
		};

		enum HksBytecodeSharingMode
		{
			HKS_BYTECODE_SHARING_OFF = 0x0,
			HKS_BYTECODE_SHARING_ON = 0x1,
			HKS_BYTECODE_SHARING_SECURE = 0x2,
		};

		struct HksGcWeights
		{
			int m_removeString;
			int m_finalizeUserdataNoMM;
			int m_finalizeUserdataGcMM;
			int m_cleanCoroutine;
			int m_removeWeak;
			int m_markObject;
			int m_traverseString;
			int m_traverseUserdata;
			int m_traverseCoroutine;
			int m_traverseWeakTable;
			int m_freeChunk;
			int m_sweepTraverse;
		};

		struct GarbageCollector_Stack
		{
			void* m_storage;
			unsigned int m_numEntries;
			unsigned int m_numAllocated;
		};

		struct ProtoList
		{
			void** m_protoList;
			unsigned __int16 m_protoSize;
			unsigned __int16 m_protoAllocSize;
		};

		struct GarbageCollector
		{
			int m_target;
			int m_stepsLeft;
			int m_stepLimit;
			HksGcWeights m_costs;
			int m_unit;
			_SETJMP_FLOAT128(*m_jumpPoint)[16];
			lua_State* m_mainState;
			lua_State* m_finalizerState;
			void* m_memory;
			int m_phase;
			GarbageCollector_Stack m_resumeStack;
			GarbageCollector_Stack m_greyStack;
			GarbageCollector_Stack m_remarkStack;
			GarbageCollector_Stack m_weakStack;
			int m_finalizing;
			HksObject m_safeTableValue;
			lua_State* m_startOfStateStackList;
			lua_State* m_endOfStateStackList;
			lua_State* m_currentState;
			HksObject m_safeValue;
			void* m_compiler;
			void* m_bytecodeReader;
			void* m_bytecodeWriter;
			int m_pauseMultiplier;
			int m_stepMultiplier;
			bool m_stopped;
			int(__fastcall* m_gcPolicy)(lua_State*);
			unsigned __int64 m_pauseTriggerMemoryUsage;
			int m_stepTriggerCountdown;
			unsigned int m_stringTableIndex;
			unsigned int m_stringTableSize;
			UserData* m_lastBlackUD;
			UserData* m_activeUD;
		};

		enum MemoryManager_ChunkColor
		{
			RED = 0x0,
			BLACK = 0x1,
		};

		struct ChunkList
		{
			ChunkHeader m_prevToStart;
		};

		enum Hks_DeleteCheckingMode
		{
			HKS_DELETE_CHECKING_OFF = 0x0,
			HKS_DELETE_CHECKING_ACCURATE = 0x1,
			HKS_DELETE_CHECKING_SAFE = 0x2,
		};

		struct MemoryManager
		{
			void* (__fastcall* m_allocator)(void*, void*, unsigned __int64, unsigned __int64);
			void* m_allocatorUd;
			MemoryManager_ChunkColor m_chunkColor;
			unsigned __int64 m_used;
			unsigned __int64 m_highwatermark;
			ChunkList m_allocationList;
			ChunkList m_sweepList;
			ChunkHeader* m_lastKeptChunk;
			lua_State* m_state;
			ChunkList m_deletedList;
			int m_deleteMode;
			Hks_DeleteCheckingMode m_deleteCheckingMode;
		};

		struct StaticStringCache
		{
			HksObject m_objects[41];
		};

		enum HksBytecodeEndianness
		{
			HKS_BYTECODE_DEFAULT_ENDIAN = 0x0,
			HKS_BYTECODE_BIG_ENDIAN = 0x1,
			HKS_BYTECODE_LITTLE_ENDIAN = 0x2,
		};

		struct RuntimeProfileData_Stats
		{
			unsigned __int64 hksTime;
			unsigned __int64 callbackTime;
			unsigned __int64 gcTime;
			unsigned __int64 cFinalizerTime;
			unsigned __int64 compilerTime;
			unsigned int hkssTimeSamples;
			unsigned int callbackTimeSamples;
			unsigned int gcTimeSamples;
			unsigned int compilerTimeSamples;
			unsigned int num_newuserdata;
			unsigned int num_tablerehash;
			unsigned int num_pushstring;
			unsigned int num_pushcfunction;
			unsigned int num_newtables;
		};

		struct RuntimeProfileData
		{
			__int64 stackDepth;
			__int64 callbackDepth;
			unsigned __int64 lastTimer;
			RuntimeProfileData_Stats frameStats;
			unsigned __int64 gcStartTime;
			unsigned __int64 finalizerStartTime;
			unsigned __int64 compilerStartTime;
			unsigned __int64 compilerStartGCTime;
			unsigned __int64 compilerStartGCFinalizerTime;
			unsigned __int64 compilerCallbackStartTime;
			__int64 compilerDepth;
			void* outFile;
			lua_State* rootState;
		};

		struct HksGlobal
		{
			MemoryManager m_memory;
			GarbageCollector m_collector;
			StringTable m_stringTable;
			HksBytecodeSharingMode m_bytecodeSharingMode;
			unsigned int m_tableVersionInitializer;
			HksObject m_registry;
			ProtoList m_protoList;
			HashTable* m_structProtoByName;
			ChunkList m_userDataList;
			lua_State* m_root;
			StaticStringCache m_staticStringCache;
			void* m_debugger;
			void* m_profiler;
			RuntimeProfileData m_runProfilerData;
			HksCompilerSettings m_compilerSettings;
			int(__fastcall* m_panicFunction)(lua_State*);
			void* m_luaplusObjectList;
			int m_heapAssertionFrequency;
			int m_heapAssertionCount;
			void (*m_logFunction)(lua_State*, const char*, ...);
			HksBytecodeEndianness m_bytecodeDumpEndianness;
		};

		struct lua_State : ChunkHeader
		{
			HksGlobal* m_global;
			CallStack m_callStack;
			ApiStack m_apistack;
			UpValue* pending;
			HksObject globals;
			HksObject m_cEnv;
			CallSite* m_callsites;
			int m_numberOfCCalls;
			void* m_context;
			InternString* m_name;
			lua_State* m_nextState;
			lua_State* m_nextStateStack;
			Status m_status;
			HksError m_error;
		};
	}
}

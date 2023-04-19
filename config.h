/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 20;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 13;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 20;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const unsigned int systraypinning = 1;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;    /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;        /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */

static const char *fonts[]          = {
    "Noto Sans:size=14:antialias=true:autohint=true",
    "Noto Color Emoji:size=14:antialias=true:autohint=true"
    "Font Awesome 5 Free:style=Solid:size=14:antialias=true:autohint=true",
    "Siji:size=14:antialias=true:autohint=true",
    "OpenSymbol:size=14:antialias=true:autohint=true",
    "Font Awesome:size=14:antialias=true:autohint=true",
    "Font Awesome 5 Brands Regular:style=Regular:size=14:antialias=true:autohint=true"
};

static char normbgcolor[]           = "#222222";
static char normbordercolor[]       = "#444444";
static char normfgcolor[]           = "#bbbbbb";
static char selfgcolor[]            = "#eeeeee";
static char selbordercolor[]        = "#005577";
static char selbgcolor[]            = "#005577";

static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
    /* xprop(1):
     *  WM_CLASS(STRING) = instance, class
     *  WM_NAME(STRING) = title
     */
    /* class                    instance    title                   tags mask        isfloating   isterminal noswallow monitor */
    { "Gimp",                    NULL,       NULL,                   1 << 8,          0,           0,         0,        -1},
    { "firefox",                 NULL,       NULL,                   1 << 1,          0,           0,         0,        -1},
    { "St",                      NULL,       NULL,                   0,               0,           1,         0,        -1},
    { "kcalc",                   NULL,       NULL,                   0,               1,           0,         0,        -1},
    { "Qsynt",                   NULL,       NULL,                   0,               1,           0,         0,        -1},
    { "copyq",                   NULL,       NULL,                   0,               1,           0,         0,        -1},
    { "Nvidia-settings",         NULL,       NULL,                   0,               1,           0,         0,        -1},
    { "Pcsxr",                   NULL,       NULL,                   0,               1,           0,         0,        -1},
    { "CfgDFInput",              NULL,       NULL,                   0,               1,           0,         0,        -1},
    { "arandr",                  NULL,       NULL,                   0,               1,           0,         0,        -1},
    { "BeeBEEP",                 NULL,       NULL,                   0,               1,           0,         0,        -1},
    { "Jack-rack",               NULL,       NULL,                   0,               1,           0,         0,        -1},
    { "QjackCtl",                NULL,       NULL,                   0,               1,           0,         0,        -1},
    { "Yad",                     NULL,       NULL,                   0,               1,           0,         0,        -1},
    { "dosbox",                  NULL,       NULL,                   0,               1,           0,         0,        -1},
    { "kamoso",                  NULL,       NULL,                   0,               1,           0,         0,        -1},
    { "Arandr",                  NULL,       NULL,                   0,               1,           0,         0,        -1},
    { "mpv",                     NULL,       NULL,                   0,               1,           0,         0,        -1},
    { "SimpleScreenRecorder",    NULL,       NULL,                   0,               1,           0,         0,        -1},
    { "MediaWriter",             NULL,       NULL,                   0,               1,           0,         0,        -1},
    { "winecfg.exe",             NULL,       NULL,                   0,               1,           0,         0,        -1},
    { "dolphin-emu",             NULL,       NULL,                   0,               1,           0,         0,        -1},
    { "Pavucontrol",             NULL,       NULL,                   0,               1,           0,         0,        -1},
    { NULL,                      NULL,       "Event Tester",         0,               1,           0,         1,        -1},
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

/* mouse scroll resize */
static const int scrollsensetivity = 30; /* 1 means resize window by 1 pixel for each scroll event */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
    /* symbol     arrange function */
    { "[]=",      tile },    /* first entry is default */
    { "[M]",      monocle },
    { "|M|",      centeredmaster },
    { ">M>",      centeredfloatingmaster },
    { "TTT",      bstack },
    { "===",      bstackhoriz },
    { "[@]",      spiral },
    { "[\\]",     dwindle },
    { "><>",      NULL },    /* no layout function means floating behavior */
};

/* key definitions */
#define MODKEY Mod4Mask

#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

#define STACKKEYS(MOD,ACTION) \
    { MOD, XK_j,     ACTION##stack, {.i = INC(+1) } }, \
    { MOD, XK_k,     ACTION##stack, {.i = INC(-1) } }, \
    { MOD, XK_backslash, ACTION##stack, {.i = PREVSEL } }, \
    { MOD, XK_c,     ACTION##stack, {.i = 0 } }, \
    { MOD, XK_a,     ACTION##stack, {.i = 1 } }, \
    { MOD, XK_n,     ACTION##stack, {.i = 2 } }, \
    { MOD, XK_e,     ACTION##stack, {.i = -1 } },   /* LAST POSITION */

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "120x34", NULL };

#include <X11/XF86keysym.h>
static const Key keys[] = {
    /* modifier                     key        function        argument */
    STACKKEYS(MODKEY,                          focus)
    STACKKEYS(MODKEY|ShiftMask,                push)
    TAGKEYS(            XK_1,       0)
    TAGKEYS(            XK_2,       1)
    TAGKEYS(            XK_3,       2)
    TAGKEYS(            XK_4,       3)
    TAGKEYS(            XK_5,       4)
    TAGKEYS(            XK_6,       5)
    TAGKEYS(            XK_7,       6)
    TAGKEYS(            XK_8,       7)
    TAGKEYS(            XK_9,       8)

    { MODKEY,           XK_t,               setlayout,      {.v = &layouts[0]} }, /* "[]=",  tile    */
    { MODKEY|ShiftMask, XK_t,               setlayout,      {.v = &layouts[1]} }, /* "[M]",  monocle */
    { MODKEY,           XK_y,               setlayout,      {.v = &layouts[2]} }, /* "|M|",  centeredmaster */
    { MODKEY|ShiftMask, XK_y,               setlayout,      {.v = &layouts[3]} }, /* ">M>",  centeredfloatingmaster */
    { MODKEY,           XK_u,               setlayout,      {.v = &layouts[4]} }, /* "TTT",  bstack  */
    { MODKEY|ShiftMask, XK_u,               setlayout,      {.v = &layouts[5]} }, /* "===",  bstackhoriz */
    { MODKEY,           XK_i,               setlayout,      {.v = &layouts[6]} }, /* "[@]",  spiral  */
    { MODKEY|ShiftMask, XK_i,               setlayout,      {.v = &layouts[7]} }, /* "[\\]", dwindle */
    { MODKEY,           XK_o,               incnmaster,     {.i = +1 } },
    { MODKEY|ShiftMask, XK_o,               incnmaster,     {.i = -1 } },
    { MODKEY,           XK_0,               view,           {.ui = ~0 } },
    { MODKEY|ShiftMask, XK_0,               tag,            {.ui = ~0 } },
    { MODKEY,           XK_Tab,             view,           {0} },
    { MODKEY,           XK_q,               killclient,     {0} },
    { MODKEY,           XK_s,               togglesticky,   {0} },
    { MODKEY|ShiftMask, XK_g,               togglegaps,     {0} },
    { MODKEY,           XK_g,               defaultgaps,    {0} },
    { MODKEY,           XK_f,               togglefullscr,  {0} },
    { MODKEY|ShiftMask, XK_f,               setlayout,      {.v = &layouts[8]} },
    { MODKEY,           XK_h,               setmfact,       {.f = -0.05} },
    { MODKEY,           XK_l,               setmfact,       {.f = +0.05} },
    { MODKEY,           XK_z,               incrgaps,       {.i = +1 } },
    { MODKEY|ShiftMask, XK_z,               incrgaps,       {.i = -1 } },
    { MODKEY,           XK_Left,            focusmon,       {.i = -1 } },
    { MODKEY|ShiftMask, XK_Left,            tagmon,         {.i = -1 } },
    { MODKEY,           XK_Right,           focusmon,       {.i = +1 } },
    { MODKEY|ShiftMask, XK_Right,           tagmon,         {.i = +1 } },
    { MODKEY,           XK_BackSpace,       spawn,          SHCMD("sysact") },
    { MODKEY,           XK_w,               spawn,          SHCMD("$BROWSER") },
    { MODKEY|ShiftMask, XK_w,               spawn,          SHCMD("st -e sudo nmtui") },
    { MODKEY,           XK_r,               spawn,          SHCMD("st -e ~/.local/bin/vifm") },
    { MODKEY,           XK_p,               spawn,          SHCMD("playercontrol player play-pause") },
    { MODKEY|ShiftMask, XK_p,               spawn,          SHCMD("playercontrol player stop") },
    { MODKEY,           XK_less,            spawn,          SHCMD("playercontrol seek 10-") },
    { MODKEY|ShiftMask, XK_less,            spawn,          SHCMD("playercontrol seek 120+") },
    { MODKEY,           XK_greater,         spawn,          SHCMD("playercontrol seek 10+") },
    { MODKEY|ShiftMask, XK_greater,         spawn,          SHCMD("playercontrol seek 120+") },
    { MODKEY,           XK_d,               spawn,          SHCMD("rofi -show drun -theme sidebar -show-icons -drun-show-actions -icon-theme breeze-dark") },
    { MODKEY|ShiftMask, XK_d,               spawn,          {.v = dmenucmd } },
    { MODKEY,           XK_Return,          spawn,          {.v = termcmd } },
    { MODKEY|ShiftMask, XK_Return,          togglescratch,  {.v = scratchpadcmd } },
    { MODKEY,           XK_x,               spawn,          SHCMD("lock-screen") },
    { MODKEY|ShiftMask, XK_v,               spawn,          SHCMD("{ killall picom || setsid picom & } ; feh --bg-fill ~/.config/i3/default-wallpaper") },
    { MODKEY,           XK_v,               spawn,          SHCMD("camtoggle") },
    { MODKEY,           XK_b,               togglebar,      {0} },
    { MODKEY,           XK_m,               spawn,          SHCMD("st -e ncmpcpp") },
    { MODKEY,           XK_Insert,          spawn,          SHCMD("notify-send \"📋 Clipboard contents:\" \"$(xclip -o -selection clipboard)\"") },
    { MODKEY,           XK_F2,              quit,           {1} },
    { MODKEY,           XK_F3,              spawn,          SHCMD("displayselect") },
    { MODKEY,           XK_F5,              xrdb,           {.v = NULL } },
    { MODKEY,           XK_space,           zoom,           {0} },
    { MODKEY,           XK_comma,           spawn,          SHCMD("light -U 5") },
    { MODKEY,           XK_period,          spawn,          SHCMD("light -A 5") },
    { MODKEY|ShiftMask, XK_space,           togglefloating, {0} },
    { 0,                XK_Print,           spawn,          SHCMD("maim pic-full-$(date '+%y%m%d-%H%M-%S').png") },
    { ShiftMask,        XK_Print,           spawn,          SHCMD("maimpick") },
    { 0, XF86XK_AudioMute,          spawn,      SHCMD("volume-ctl toggle; pkill -RTMIN+16 dwmblocks") },
    { 0, XF86XK_AudioRaiseVolume,   spawn,      SHCMD("volume-ctl up; pkill -RTMIN+16 dwmblocks") },
    { 0, XF86XK_AudioLowerVolume,   spawn,      SHCMD("volume-ctl down; pkill -RTMIN+16 dwmblocks") },
    { 0, XF86XK_AudioPrev,          spawn,      SHCMD("playercontrol player previous") },
    { 0, XF86XK_AudioNext,          spawn,      SHCMD("playercontrol player next") },
    { 0, XF86XK_AudioPause,         spawn,      SHCMD("playercontrol player pause") },
    { 0, XF86XK_AudioPlay,          spawn,      SHCMD("playercontrol player play-pause") },
    { 0, XF86XK_AudioStop,          spawn,      SHCMD("playercontrol player stop") },
    { 0, XF86XK_PowerOff,           spawn,      SHCMD("[ \"$(printf \"No\\nYes\" | dmenu -i -nb darkred -sb red -sf white -nf gray -p \"Shutdown computer?\")\" = Yes ] && sudo -A shutdown -h now") },
    { 0, XF86XK_Calculator,         spawn,      SHCMD("kcalc") },
    { 0, XF86XK_Sleep,              spawn,      SHCMD("sudo -A zzz") },
    { 0, XF86XK_WWW,                spawn,      SHCMD("$BROWSER") },
    { 0, XF86XK_ScreenSaver,        spawn,      SHCMD("monitor-off") },
    { 0, XF86XK_WebCam,             spawn,      SHCMD("camtoggle") },
    { 0, XF86XK_TouchpadToggle,     spawn,      SHCMD("touchpad-toggle") },
    { 0, XF86XK_MonBrightnessUp,    spawn,      SHCMD("light -A 5") },
    { 0, XF86XK_MonBrightnessDown,  spawn,      SHCMD("light -U 5") },
};

/* resizemousescroll direction argument list */
static const int scrollargs[][2] = {
    /* width change         height change */
    { +scrollsensetivity,   0 },
    { -scrollsensetivity,   0 },
    { 0,                    +scrollsensetivity },
    { 0,                    -scrollsensetivity },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
    /* click                event mask      button          function        argument */
    { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
    { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
    { ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
    { ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
    { ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
    { ClkStatusText,        0,              Button4,        sigdwmblocks,   {.i = 4} },
    { ClkStatusText,        0,              Button5,        sigdwmblocks,   {.i = 5} },
    { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
    { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
    { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
    { ClkClientWin,         MODKEY,         Button4,        resizemousescroll, {.v = &scrollargs[0]} },
    { ClkClientWin,         MODKEY,         Button5,        resizemousescroll, {.v = &scrollargs[1]} },
    { ClkClientWin,         MODKEY,         Button6,        resizemousescroll, {.v = &scrollargs[2]} },
    { ClkClientWin,         MODKEY,         Button7,        resizemousescroll, {.v = &scrollargs[3]} },
    { ClkTagBar,            0,              Button1,        view,           {0} },
    { ClkTagBar,            0,              Button3,        toggleview,     {0} },
    { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};


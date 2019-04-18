/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */
static const char *fonts[]          = { "Inconsolata:size=9" };
//static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char col_orange[]      = "#FF8C00";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_orange  },
};

/* static const unsigned int gappx       = 10; */
/* static const unsigned int gapp_singx  = 300; */
/* static const unsigned int gapp_singy  = 50; */

#ifdef winterland
static const unsigned int gappx       = 0;
#endif /* winterland */

#ifdef sylvester
static const unsigned int gappx       = 0;
#endif /* sylvester */

static const unsigned int gapp_singx  = 0;
static const unsigned int gapp_singy  = 0;

/* static unsigned int baralpha = 0xd0; */
/* static unsigned int borderalpha = OPAQUE; */

#define baralpha 0x00
#define borderalpha OPAQUE


static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Pidgin",   NULL,       "Buddy List", 1 << 4,    1,              -1},
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *rofiruncmd[] = {"rofi", "-show", "run", "-theme", "Arc", "-lines", "20", "-opacity", "20", "-font", "Inconsolata 10", NULL };
static const char *termcmd[]  = { "urxvt", NULL };
static const char *vol_up[]  = { "/home/evas/bin/vol_up.sh", NULL };
static const char *vol_down[]  = { "/home/evas/bin/vol_down.sh", NULL };
static const char *suspend_monitor[]  = { "/home/evas/bin/suspend_monitor", NULL };
static const char *suspend[]  = { "sudo", "/usr/sbin/pm-suspend", NULL };
static const char *mpd_toggle[]  = { "mpc", "toggle", NULL };
static const char *mpd_next[]  = { "mpc", "next", NULL };
static const char *mpd_prev[]  = { "mpc", "prev", NULL };
static const char *notif_info[]  = { "/home/evas/bin/notif_info", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_r,      spawn,          {.v = rofiruncmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ Mod1Mask,                     XK_Tab,    focusstack,     {.i = +1 } },
	/* { MODKEY,                       XK_k,      focusstack,     {.i = -1 } }, */
	/* { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } }, */
	/* { MODKEY,                       XK_d,      incnmaster,     {.i = -1 } }, */
	{ MODKEY|ShiftMask,             XK_j,      setmfact,       {.f = -0.05} },
	{ MODKEY|ShiftMask,             XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_l,      x_nexttag,      {0} },
        { MODKEY,                       XK_j,      x_prevtag,      {0} },
	{ MODKEY,                       XK_F12,    spawn,          {.v = vol_up } },
	{ MODKEY,                       XK_F11,    spawn,          {.v = vol_down } },
	{ MODKEY,                       XK_F2,     spawn,          {.v = suspend_monitor } },
	{ MODKEY,                       XK_F1,     spawn,          {.v = suspend } },
	{ MODKEY,                       XK_F1,     spawn,          {.v = suspend } },
	{ MODKEY,                       XK_p,      spawn,          {.v = mpd_toggle } },
	{ MODKEY,                       XK_bracketright,      spawn,          {.v = mpd_next } },
	{ MODKEY,                       XK_bracketleft,      spawn,          {.v = mpd_prev } },
	{ MODKEY,                       XK_s,      spawn,          {.v = notif_info } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         Mod1Mask,       Button1,        movemouse,      {0} },
	{ ClkClientWin,         Mod1Mask,       Button2,        togglefloating, {0} },
	{ ClkClientWin,         Mod1Mask,       Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};


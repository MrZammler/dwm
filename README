## Synopsis

This is my local "fork" of dwm.

dwm is an extremely fast, small, and dynamic window manager for X.

For more information. visit: https://dwm.suckless.org/

There are many tiling window managers, and I tried a few. dwm ticks almost all the boxes I wanted. Let's me have Alt-Tab to cycle through windows on a desktop (i3 doesn't want that), is not picky about full screen youtube/mplayer windows (xmonad has a thing there), has a usable bar (bspwm doesn't).

It's main tiling algorithm is a master pane on the left and stacked windows on the right.

## Configuration

The configuration of dwm is done by creating a custom config.h and (re)compiling the source code. This fork is configured for use with a Poker 3 keyboard. Main points of config:

Key|Operation 
--- | ---
Win-r|run rofi 
Win-Enter|spawm a urxvt terminal
Alt-Tab|focus next window
Win-Shift-l|Change master/stack ration (more master)
Win-Shift-j|Change master/stack ration (less master)
Win-Shift-Enter|Get the focuced window to master area
Win-Tab|Focus previous workspace (tag)
Win-q|Kill focused window
Win-z|Set tiled layout
Win-x|Set floating layout
Win-c|Set monocle layout
Win-0|View all open windows
Win-l|View next workspace (tag)
Win-j|View previous workspace (tag)
Win-NUM|Switch to NUM workspace (tag)

## Patches

Dwm can be extended with patches. It's main code only contains the bare essentials, so people tend to add a few of those. Since the patches (and configuration) alter the source code, each installation is unique and a fork of it's own. This fork contains the following patches:

dwm-alpha
dwm-pertag
dwm-uselessgap

## Custom stuff

There are also two variables, not found in dwm or in other patches. gapp_singx and gapp_singy will set a gap when there is only one window open, or in monocle mode. This was because I wanted to have a single window in the center of my screen rather than occuping all of the 1440p monitor.



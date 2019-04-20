## Synopsis

This is my local "fork" of dwm.

dwm is an extremely fast, small, and dynamic window manager for X.

For more information. visit: https://dwm.suckless.org/

## Configuration

The configuration of dwm is done by creating a custom config.h and (re)compiling the source code. This fork is configured for use with a Poker 3 keyboard. Main points of config:

Key|Operation 
--- | ---
Win-r|run rofi 
Win-Enter|spawm a urxvt terminal
Alt-Tab|focus next window


## Patches

Dwm can be extended with patches. It's main code only contains the bare essentials, so people tend to add a few of those. Since the patches (and configuration) alter the source code, each installation is unique and a fork of it's own. This fork contains the following patches:

dwm-alpha
dwm-pertag
dwm-uselessgap





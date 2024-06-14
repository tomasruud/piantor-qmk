#!/bin/sh
git submodule update --init --recursive

dest="qmk_firmware/keyboards/beekeeb/piantor_pro/keymaps/tomasruud"

rm -rfd $dest
mkdir -p $dest
cp keymap.c $dest/keymap.c

(cd qmk_firmware && util/docker_build.sh beekeeb/piantor_pro:tomasruud)

rm -rfd $dest

rm -f beekeeb_piantor_pro_tomasruud.uf2
mv qmk_firmware/.build/beekeeb_piantor_pro_tomasruud.uf2 .

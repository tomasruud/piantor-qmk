.PHONY: clean

keymap   := beekeeb/piantor_pro:tomasruud
bin_name := beekeeb_piantor_pro_tomasruud.uf2
qmk_dir  := qmk_firmware
qmk_map := $(qmk_dir)/keyboards/beekeeb/piantor_pro/keymaps/tomasruud

all: $(bin_name)

$(bin_name): keymap.c
	git submodule update --init --recursive
	mkdir -p $(qmk_map)
	cp keymap.c $(qmk_map)/keymap.c
	(cd $(qmk_dir) && util/docker_build.sh $(keymap))
	mv $(qmk_dir)/.build/$(bin_name) .
	rm -rfd $(qmk_map)

clean:
	rm -rfd $(qmk_map)
	rm -f $(bin_name)

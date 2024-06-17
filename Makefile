.PHONY: clean

keymap   := beekeeb/piantor_pro:tomasruud
bin_name := beekeeb_piantor_pro_tomasruud.uf2
qmk_dir  := qmk_firmware
qmk_map := $(qmk_dir)/keyboards/beekeeb/piantor_pro/keymaps/tomasruud

all: $(bin_name)

$(bin_name):
	git submodule update --init --recursive
	cp -r ./src $(qmk_map)
	(cd $(qmk_dir) && util/docker_build.sh $(keymap))
	mv $(qmk_dir)/.build/$(bin_name) out/.
	rm -rfd $(qmk_map)

clean:
	rm -rfd $(qmk_map)
	rm -f ./bin/$(bin_name)


CMAKE=docker run --name pico-sdk --rm -v ${PWD}:/home/dev:rw --user $(shell id -u) -w /home/dev/ pico-sdk:latest cmake

build: configure
	$(CMAKE) --build _build

clean:
	rm -Rf _build

configure:
	$(CMAKE) -B _build . -DPICO_BOARD=pico_w -DPICO_SDK_PATH=/usr/local/picosdk

install: build
	$(CMAKE) --install _build

flash: build
	mount /dev/sda1
	cp _build/simple_example.uf2 /mnt/pico
	umount /dev/sda1

debug:
	cat /dev/ttyACM0


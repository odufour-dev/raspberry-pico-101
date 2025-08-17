
build: configure
	docker run --name pico-sdk --rm -v ${PWD}:/home/dev -w /home/dev/ pico-sdk:latest cmake --build _build

clean:
	sudo rm -Rf _build

configure:
	docker run --name pico-sdk --rm -v ${PWD}:/home/dev -w /home/dev/ pico-sdk:latest cmake -B _build . -DPICO_BOARD=pico_w -DPICO_SDK_PATH=/usr/local/picosdk

install: build
	docker run --name pico-sdk --rm -v ${PWD}:/home/dev -w /home/dev/ pico-sdk:latest cmake --install _build

flash: build
	sudo mount /dev/sda1 /mnt/pico
	sudo cp _build/simple_example.uf2 /mnt/pico
	sudo umount /dev/sda1

debug:
	cat /dev/ttyACM0



build: configure
	docker run --name pico-sdk --rm -v ${PWD}:/home/dev -w /home/dev/ pico-sdk:latest cmake --build _build

configure:
	docker run --name pico-sdk --rm -v ${PWD}:/home/dev -w /home/dev/ pico-sdk:latest cmake -B _build . -DPICO_BOARD=pico_w

install: build
	docker run --name pico-sdk --rm -v ${PWD}:/home/dev -w /home/dev/ pico-sdk:latest cmake --install _build

flash: build
	sudo mount /dev/sda1 /mnt/pico
	sudo cp _build/simple_example.uf2 /mnt/pico
	sudo umount /dev/sda1


build: configure
	docker run --name pico-sdk --rm -v ${PWD}:/home/dev -w /home/dev/ pico-sdk:latest cmake --build _build

configure:
	docker run --name pico-sdk --rm -v ${PWD}:/home/dev -w /home/dev/ pico-sdk:latest cmake -B _build .

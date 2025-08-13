# Pico 101

Project to play and test the Pico PI

## Documentation

- [Getting started with Pico](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf)

Will use docker container to compile the binaries, [reference](https://github.com/lukstep/raspberry-pi-pico-docker-sdk)

## Run the container

```shell
docker run -d -it --name pico-sdk --mount type=bind,source=${PWD},target=/home/dev lukstep/raspberry-pi-pico-sdk:latest
docker exec -it pico-sdk /bin/sh
```

## Compile the executable

```shell
cd /home/dev
mkdir build
cd build
cmake .. && make -j4
```

## OpenOCD to flash and debug

### Prerequisites

Install OpenOCD : required to flash the board, the Docker container will connect to OpenOCD for flashing

### Start OpenOCD

```shell
sudo openocd -f interface/cmsis-dap.cfg -f target/rp2040.cfg -c 'bindto 0.0.0.0' -c 'adapter speed 5000' -c 'init'
```



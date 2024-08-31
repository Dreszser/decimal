#!/bin/bash
cd ../

docker rmi -f s21_decimal
docker build -t s21_decimal -f Docker/Dockerfile .
docker run --name=decimal -p 8000:8000 --rm -it s21_decimal
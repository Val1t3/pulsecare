FROM ubuntu:latest

WORKDIR /app

COPY . /app

# Install dependencies
RUN apt update && apt install -y \
    build-essential \
    valgrind \
    gdb \
    cmake \
    android-tools-adb \
    && apt clean

CMD ["tail", "-f", "/dev/null"]

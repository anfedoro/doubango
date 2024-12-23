# Start with an Ubuntu 22.04 base image
FROM python:3.11-bullseye

# Install necessary packages
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    libtool \
    autoconf \
    cmake \
    gcc \
    g++ \
    pkgconf \
    nasm \
    yasm \
    wget \
    git \
    libssl-dev \
    libmnl-dev \
    patchelf \
    python3-dev \
    python3-pip \
#    swig \
    && apt-get clean

RUN python3 -m pip install --upgrade pip setuptools wheel auditwheel patchelf

# Clone doubango repository into container
COPY doubango /doubango
RUN wget https://prdownloads.sourceforge.net/swig/swig-4.3.0.tar.gz

# Unpack and Build swig
RUN tar -xvzf /swig-4.3.0.tar.gz
WORKDIR /swig-4.3.0
RUN ./configure
RUN make -j8
RUN make install

#build doubango
WORKDIR /doubango
RUN cmake -S . -B out
RUN cmake --build out/ -j 8

# Create wheel package
RUN mkdir -p /dist


# Check and repair wheel using auditwheel
RUN auditwheel repair /doubango/out/bindings/python/dist/*.whl -w /dist  --plat manylinux_2_34_x86_64
RUN cp /doubango/out/plugins/ipsec_linux/ipsec.so /dist/

WORKDIR /dist

# Keep the container running by tailing /dev/null
CMD ["/usr/bin/tail", "-f", "/dev/null"]


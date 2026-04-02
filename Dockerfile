# CSE 101 — Linux build environment (matches GitLab CI: ubuntu:22.04 + gcc/make/valgrind).
# Build from repo root:  docker build -f docker/base.Dockerfile -t cse101-build .
# Run in your project:   docker run --rm -v "${PWD}:/workspace" -w /workspace cse101-build make

FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive \
    LANG=C.UTF-8 \
    LC_ALL=C.UTF-8

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        build-essential \
        make \
        valgrind \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace

# Override when running: docker run ... cse101-build ./hw0
CMD ["make"]

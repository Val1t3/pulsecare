# pulsecare

# Container
- [Docker](https://www.docker.com/)

Build docker image
```bash
docker build -t pulsecare .
```

Run docker container
```bash
docker run -it -v $(pwd):/app pulsecare
```
FROM golang:alpine AS builder

WORKDIR /app

COPY go.mod ./
RUN go mod download

COPY . .

# Отладочная информация
RUN echo "Building..." && \
    pwd && \
    ls -la cmd/game_controller/ && \
    CGO_ENABLED=0 go build -o /game_service ./cmd/game_controller && \
    ls -la /game_service

FROM alpine:latest
WORKDIR /root/

# Копируем из абсолютного пути
COPY --from=builder /game_service .

RUN ls -la

CMD ["./game_service"]
FROM golang:alpine AS builder

WORKDIR /app

COPY go.mod ./
RUN go mod download

COPY . .

# Отладочная информация
RUN echo "Building..." && \
    pwd && \
    ls -la cmd/auth/ && \
    CGO_ENABLED=0 go build -o /auth ./cmd/auth && \
    ls -la /auth

FROM alpine:latest
WORKDIR /root/

# Копируем из абсолютного пути
COPY --from=builder /auth .

RUN ls -la

CMD ["./auth"]
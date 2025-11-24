FROM golang:alpine AS builder

WORKDIR /app

COPY go.mod ./
RUN go mod download

COPY . .

# Отладочная информация
RUN echo "Building..." && \
    pwd && \
    ls -la cmd/gateway/ && \
    CGO_ENABLED=0 go build -o /gateway ./cmd/gateway && \
    ls -la /gateway

FROM alpine:latest
WORKDIR /root/

# Копируем из абсолютного пути
COPY --from=builder /gateway .

RUN ls -la

CMD ["./gateway"]
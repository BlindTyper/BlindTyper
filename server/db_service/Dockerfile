FROM golang:alpine AS builder

WORKDIR /app

COPY go.mod ./
RUN go mod download

COPY . .

# Отладочная информация
RUN echo "Building..." && \
    pwd && \
    ls -la cmd/database_control/ && \
    CGO_ENABLED=0 go build -o /db_service ./cmd/database_control && \
    ls -la /db_service

FROM alpine:latest
WORKDIR /root/

# Копируем из абсолютного пути
COPY --from=builder /db_service .

RUN ls -la

CMD ["./db_service"]
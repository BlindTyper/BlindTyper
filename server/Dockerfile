# Данный Dockerfile будет использован для запуска ВСЕГО приложения. т.е для запуска образа сервисов и обобщения.

FROM alpine:latest

WORKDIR /

RUN apt-get-update & apd-get install -y <package> 

COPY . .

# определение комманды при запуске контейнера. в нашем случае будет необходимо запустить сами сервисы в т.ч db auth gateway game-engine и nginx
CMD ["python", "app.py"]

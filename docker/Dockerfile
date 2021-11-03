# docker pull gcc:10
# docker build -t app .
# docker run app


FROM gcc:10

COPY ./main.cpp .

RUN g++ main.cpp -o app
RUN chmod +x app

CMD ["./app"]


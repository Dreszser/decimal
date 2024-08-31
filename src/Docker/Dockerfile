FROM ubuntu:24.04

RUN apt-get update && apt-get install -y \
    gcc \
    make \
    check \
    gcovr \
    python3 

WORKDIR /usr/src/app

COPY ./ ./

RUN make gcov_report

CMD ["python3", "-m", "http.server", "8000", "--directory", "report"]
rm *.o Something_client.cpp
g++ -Wall -I/usr/local/include/thrift -c Something.cpp -o something.o
g++ -Wall -I/usr/local/include/thrift -c Something_server.cpp -o server.o
g++ -Wall -I/usr/local/include/thrift -c your_thrift_file_constants.cpp -o constants.o
g++ -Wall -I/usr/local/include/thrift -c your_thrift_file_types.cpp -o types.o
g++ -L/usr/local/lib *.o -o Something_server -lthrift


cp ../Something_client.cpp ../gen-cpp/
g++ -Wall -I/usr/local/include/thrift -c Something_client.cpp -o client.o
g++ -L/usr/local/lib client.o something.o constants.o types.o -o Something_client -lthrift


#thrift --gen cpp your_thrift_file.thrift
cp make.sh gen-cpp/
cd gen-cpp
mv Something_server.skeleton.cpp Something_server.cpp 
sh make.sh

#include "LruCache.h"
#include <curl/curl.h>
#include <transport/TSocket.h>
#include <transport/TBufferTransports.h>
#include <protocol/TBinaryProtocol.h>
#include <string.h>

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using namespace Lru;

int main(int argc, char **argv) {
	//Create the connection
	boost::shared_ptr<TSocket> socket(new TSocket("localhost", 9090));
	boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
	boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

	//Open connection to server
	LruCacheClient client(protocol);
	transport->open();

	//Call proxy
	std::string url = "www.yahoo.com";
	std::string data;
	client.getURL(data, url);

	url = "www.google.com";
	client.getURL(data, url);

	url = "www.yahoo.com";
	client.getURL(data, url);

	url = "www.bing.com";
	client.getURL(data, url);  

	url = "www.bing.com";
	client.getURL(data, url);

	url = "www.yahoo.com";
	client.getURL(data, url);

	url = "www.cnn.com";
	client.getURL(data, url);

	//Close connection
	transport->close();

	return 0;
}

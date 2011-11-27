#include "pluma/pluma.hpp"
#include "server/iserver.hpp"


int main(int argc, char* argv[])
{
	pluma::Pluma plugins;
	plugins.loadFromFolder("../plug");

	server::IServerPtr srv(plugins.create<server::IServerProvider>());
	assert(srv);

	srv->run(&plugins, "localhost", "29431");

	return EXIT_SUCCESS;
}


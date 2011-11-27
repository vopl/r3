#include "pluma/pluma.hpp"
#include "server/iserver.hpp"


int main(int argc, char* argv[])
{
	pluma::Pluma plugins;
	plugins.loadFromFolder("../plug");

	std::vector<server::IServerProvider*> providers;
	plugins.getProviders(providers);

	assert(!providers.empty());

	server::IServerPtr srv(providers.front()->create());

	srv->run(&plugins, "localhost", "29431");

	return EXIT_SUCCESS;
}


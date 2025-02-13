#include "ex02.hpp"

void printChain(Chain *chain, int indent) 
{
    if (chain == nullptr)
        return;

    for (int i = 0; i < indent; i++)
        std::cout << "         ";
    std::cout << " [" << chain->getNum() << "]" << std::endl;
    
    if (chain->getHead().size() > 0) 
    {
        for (int i = 0; i < chain->getHead().size(); i++) 
        {
            printChain(chain->getPair(i), indent + 1);
        }
    }
}

void printChainArray(std::vector<Chain*> array)
{
	std::cout << "Chain Array: ";
	for (std::vector<Chain*>::iterator i = array.begin(); i != array.end(); i++)
	{
		std::cout << (*i)->getNum() << " ";
	}
	std::cout << std::endl;
}

void printLayer(std::vector<Layer> layers)
{
	for (int i = 0; i < layers.size(); i++)
	{
		std::cout << " ======== Layer: " << i << std::endl;
		if (layers[i].hasTop)
		{
			std::cout << "Top: " << layers[i].top->getNum() << std::endl;
		}
		if (layers[i].hasRest)
		{
			std::cout << "Rest: " << layers[i].rest->getNum() << std::endl;
		}
	}
}
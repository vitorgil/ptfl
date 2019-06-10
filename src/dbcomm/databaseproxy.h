#pragma once

namespace ptfl
{

class Portfolio;

class DatabaseProxy
{

public:
    DatabaseProxy();

    static void save(const Portfolio& portfolio);
    static Portfolio* getPortfolio();
    static void createDefault();
};

}

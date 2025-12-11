#include "questFunctions.h"
#include "Colors.h"

Reward miningGold(const Quest& q)
{
    q.execute();
    std::cout << YELLOW << "[Quest] Kopanie złota...\n" << RESET;
    return Reward(50);
}

Reward collectSnow(const Quest& q)
{
    q.execute();
    std::cout << CYAN << "[Quest] Zbieranie śniegu...\n" << RESET;
    return Reward(20);
}

Reward huntReindeer(const Quest& q)
{
    q.execute();
    std::cout << MAGENTA << "[Quest] Polowanie na renifery...\n" << RESET;
    return Reward(80);
}


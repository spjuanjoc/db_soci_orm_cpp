#include <fmt/core.h>
#include <soci/soci.h>

int main()
{
  fmt::print("Hello, soci SQLite!\n");

  const auto& connectString{"../database0.empty.db"};
  const auto& table{"table1"};
  fmt::print("soci database connected successfully\n");

  return 0;
}

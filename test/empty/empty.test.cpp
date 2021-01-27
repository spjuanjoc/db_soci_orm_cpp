#include "catch2/catch.hpp"
#include "soci/soci.h"
#include "soci/empty/soci-empty.h"
#include <string>

const auto& connectStringEmpty{"../database0.empty.db"};
const auto& table2{"table2"};
const soci::backend_factory& backEndEmpty = *soci::factory_empty();
soci::session sqlEmpty(backEndEmpty, connectStringEmpty);

TEST_CASE("should be connected empty")
{
  CHECK( sqlEmpty.is_connected() ); //! Since soci 4.0.1
}

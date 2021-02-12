#include "catch2/catch.hpp"
#include "fmt/format.h"
#include "soci/soci.h"
#include "soci/mysql/soci-mysql.h"
#include <exception>
#include <iostream>
#include <ostream>
#include <string>

namespace test_soci_mysql
{

TEST_CASE("should successfully connect with mysql backend")
{
  const auto &connectString{"db=soci_test"}; // TODO use a valid connection string
  const auto &table{"table1"};
  const soci::backend_factory &backEnd = *soci::factory_mysql();
  soci::session sql(backEnd, connectString);
  CHECK( sql.is_connected() );
  fmt::print("soci database connected successfully with mysql backend\n");
}

} // test_soci_mysql

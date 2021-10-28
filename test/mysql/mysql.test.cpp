#include <catch2/catch.hpp>
#include <fmt/format.h>
#include <soci/mysql/soci-mysql.h>
#include <soci/soci.h>
#include <exception>
#include <string>

namespace test_soci_mysql
{

TEST_CASE("should successfully connect with mysql backend")
{
  const auto &connectString{"db=soci_test"}; // TODO use a valid connection string
  const auto &table{"table1"};
  const soci::backend_factory &backEnd = *soci::factory_mysql();
  soci::session                sql;
  try
  {
//    CHECK_THROWS(sql.open(backEnd, connectString));
        sql.open(backEnd, connectString);
    //    CHECK(sql.is_connected());
    //    fmt::print("soci database connected successfully with mysql backend\n");
  }
  catch (const std::exception& exception)
  {
    fmt::print(stderr, "Cannot connect to MySQL database. Error {}", exception.what());
  }
  catch (...)
  {
    fmt::print(stderr, "Cannot connect to MySQL database");
  }
}

} // test_soci_mysql

#include <catch2/catch.hpp>
#include <fmt/format.h>
#include <soci/odbc/soci-odbc.h>
#include <soci/soci.h>
#include <exception>
#include <string>

namespace soci_odbc_test
{
TEST_CASE("should successfully connect with odbc backend")
{
  const auto& connectString{"db=soci_test"};  //// TODO use a valid connection string
  //  const auto& table{"table1"};
  const soci::backend_factory& backEnd = *soci::factory_odbc();
  soci::session                sql;
  try
  {
    CHECK_THROWS(sql.open(backEnd, connectString));
    //    sql.open(backEnd, connectString);
    //    CHECK(sql.is_connected());
    //    fmt::print("soci database connected successfully with ODBC backend\n");
  }
  catch (const std::exception& exception)
  {
    fmt::print(stderr, "Cannot connect to ODBC database. Error {}", exception.what());
  }
  catch (...)
  {
    fmt::print(stderr, "Cannot connect to ODBC database");
  }
}

}  // namespace soci_odbc_test

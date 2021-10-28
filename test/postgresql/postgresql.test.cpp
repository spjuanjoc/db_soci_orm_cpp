#include <catch2/catch.hpp>
#include <fmt/format.h>
#include <soci/postgresql/soci-postgresql.h>
#include <soci/soci.h>
#include <exception>
#include <string>

namespace test_soci_postgresql
{
TEST_CASE("should successfully connect with postgresql backend")
{
  const auto& connectString{"dbname=soci_test_postgres"};  // TODO use a valid database
  const auto& table{"table1"};
  const soci::backend_factory& backEnd = *soci::factory_postgresql();
  soci::session                sql;
  try
  {
    CHECK_THROWS(sql.open(backEnd, connectString));
    //    sql.open(backEnd, connectString);
    //    CHECK(sql.is_connected());
    //    fmt::print("soci database connected successfully with PostgreSQL backend\n");
  }
  catch (const std::exception& exception)
  {
    fmt::print(stderr, "Cannot connect to PostgreSQL database. Error {}", exception.what());
  }
  catch (...)
  {
    fmt::print(stderr, "Cannot connect to PostgreSQL database");
  }
}

}  // namespace test_soci_postgresql

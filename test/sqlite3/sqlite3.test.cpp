#include "catch2/catch.hpp"
#include "fmt/format.h"
#include "soci/soci.h"
#include "soci/sqlite3/soci-sqlite3.h"
#include <exception>
#include <string>
#include <tuple>

namespace test_soci_sqlite3
{

const auto& connectString{"../database1.sqlite3"};
const auto& table1{"table1"};
const soci::backend_factory& backEnd = *soci::factory_sqlite3();
soci::session sql(backEnd, connectString);

bool tableExists(const std::string& tableName)
{
  bool exists = false;
  try
  {
    sql << fmt::format(R"(SELECT count(*) FROM {0} ;)", tableName);

    exists = true;
  } catch (const std::exception& ex)
  {
  }

  return exists;
}

void createTable(const std::string& tableName)
{
  if (!tableExists(tableName))
  {
    sql << fmt::format(R"(
CREATE TABLE {0}
(
    id      INTEGER,
    name    VARCHAR2(100),
    balance REAL
);)", tableName);
  }
}

void insertInto(const std::string& tableName)
{
  if (tableExists(tableName))
  {
    // language=sql
    sql << fmt::format(R"EOL(
INSERT INTO {0} (id, name, balance)
VALUES (7, 'John', 100.20),
       (9, 'Jane', 200.10);
)EOL", tableName);
  }
}

int getNumberOfRows(const std::string& tableName)
{
  int count = 0;

  if (tableExists(tableName))
  {
    sql << fmt::format(R"(SELECT count(*) FROM {0};)", tableName),
        soci::into(count);
  }

  return count;
}

bool tableDropped(const std::string& tableName)
{
  bool result = false;

  if (tableExists(tableName))
  {
    sql << fmt::format("DROP TABLE {0}", tableName);
    result = true;
  }

  return result;
}

std::tuple<int, std::string, double> getValues(const std::string& tableName, int idToFind)
{
  int id = 0;
  std::string name{};
  double balance = 0.0;

  sql << fmt::format("SELECT id, name, balance FROM {0} WHERE id = {1}", tableName, idToFind),
      soci::into(id),
      soci::into(name),
      soci::into(balance);

  return {id, name, balance};
}

TEST_CASE("should be connected")
{
  CHECK( sql.is_connected() ); //! Since soci 4.0.1
}

TEST_CASE("should try to drop a nonexistent table")
{
  tableDropped(table1);
  CHECK_FALSE( tableDropped(table1) );
}

TEST_CASE("should create a table")
{
  createTable(table1);
  CHECK( tableExists(table1) );
}

TEST_CASE("should insert two rows into table")
{
  insertInto(table1);
  CHECK( getNumberOfRows(table1) == 2 );
}

TEST_CASE("should get a row from a given value")
{
  const int idToFind = 9;
  const auto [id, name, balance] = getValues(table1, idToFind);

  CHECK( id == 9);
  CHECK( name == "Jane");
  CHECK( balance == 200.10);
}

TEST_CASE("should drop a table")
{
  CHECK( tableDropped(table1) );
}

} // test_soci_sqlite3

namespace cpp sample

struct TestStruct {
  1: i32 num1 = 0,
  2: i32 num2,
  3: optional string comment,
}

service Sample {
  TestStruct echoStruct()
}

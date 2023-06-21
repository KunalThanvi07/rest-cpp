#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include <cpprest/http_client.h>
#include "json.hpp"
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <thread>
//#include "post_struct.hpp"
using jsoncpp = nlohmann::json;
#include <sstream>
using std::stringstream;

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;
using namespace std;
#pragma comment(lib, "cpprest_2_10")



#define TRACE(msg) wcout << msg
#define TRACE_ACTION(a, k, v) wcout << a << L" (" << k << L", " << v << L")\n"

map<utility::string_t, utility::string_t> dictionary;

struct hvacdbdata
{
   string defrost_front;
   string defrost_rear;
   string air_circulation;
   string ac_state_front;
   string ac_vent_flow_front;
   string temperature_front;
   string ac_state_rear;
   string ac_vent_flow_rear;
   string temperature_rear;
} hd,po;



void from_json(const jsoncpp &j)
{
   j.at("defrost_front").get_to(hd.defrost_front);
   j.at("defrost_rear").get_to(hd.defrost_rear);
   j.at("air_circulation").get_to(hd.air_circulation);
   j.at("ac_state_front").get_to(hd.ac_state_front);
   j.at("ac_vent_flow_front").get_to(hd.ac_vent_flow_front);
   j.at("temperature_front").get_to(hd.temperature_front);
   j.at("ac_state_rear").get_to(hd.ac_state_rear);
   j.at("ac_vent_flow_rear").get_to(hd.ac_vent_flow_rear);
   j.at("temperature_rear").get_to(hd.temperature_rear);
}

web::json::value from_json()
{

   web::json::value jsonObject;
   // jsonObject[U("first_name")] = json::value::string(U("atakan"));

   jsonObject[U("defrost_front")] = json::value::string(U(hd.defrost_front));
   jsonObject[U("defrost_rear")] = json::value::string(U(hd.defrost_rear));
   jsonObject[U("air_circulation")] = json::value::string(U(hd.air_circulation));
   jsonObject[U("ac_state_front")] = json::value::string(U(hd.ac_state_front));
   jsonObject[U("ac_vent_flow_front")] = json::value::string(U(hd.ac_vent_flow_front));
   jsonObject[U("temperature_front")] = json::value::string(U(hd.temperature_front));
   jsonObject[U("ac_state_rear")] = json::value::string(U(hd.ac_state_rear));
   jsonObject[U("ac_vent_flow_rear")] = json::value::string(U(hd.ac_vent_flow_rear));
   jsonObject[U("temperature_rear")] = json::value::string(U(hd.temperature_rear));

   return jsonObject;
}


// web::json::value from_json(bool btrue)
// {

//    web::json::value jsonObject;
//    // jsonObject[U("first_name")] = json::value::string(U("atakan"));

//    jsonObject[U("defrost_front")] = json::value::string(U(hdpost.defrost_front));
//    jsonObject[U("defrost_rear")] = json::value::string(U(hdpost.defrost_rear));
//    jsonObject[U("air_circulation")] = json::value::string(U(hdpost.air_circulation));
//    jsonObject[U("ac_state_front")] = json::value::string(U(hdpost.ac_state_front));
//    jsonObject[U("ac_vent_flow_front")] = json::value::string(U(hdpost.ac_vent_flow_front));
//    jsonObject[U("temperature_front")] = json::value::string(U(hdpost.temperature_front));
//    jsonObject[U("ac_state_rear")] = json::value::string(U(hdpost.ac_state_rear));
//    jsonObject[U("ac_vent_flow_rear")] = json::value::string(U(hdpost.ac_vent_flow_rear));
//    jsonObject[U("temperature_rear")] = json::value::string(U(hdpost.temperature_rear));

//    return jsonObject;
// }


// static hvacdbdata callback(void *datahvac, int argc, char **argv, char **azColName)
// {
//    int i;

//    //    fprintf(stderr, "%s: ", (const hvac*)data.ac_state_front);

//    for (i = 0; i < argc; i++)
//    {
//       fprintf(stderr, "%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
//    }

//    struct hvacdbdata tmp = hd;
//    // tmp.defrost_front = (char *)malloc(sizeof(char) * strlen(argv[1]));

//    fprintf(stderr, "\n");
//    return tmp;
// }

void display_json(
    json::value const &jvalue)
{
   cout << jvalue.serialize() << endl;
}

void getdatafromdb()
{
   sqlite3 *db;
   bool found = false;
   char *zErrMsg = 0;
   int rc;
   // char *sql1;
   stringstream ss;
   const char *data = "Callback function called";
   // const hvac* datahvac ;
   sqlite3_stmt *stmt;

   /* Open database */
   rc = sqlite3_open("sampledatabase.db", &db);

   if (rc)
   {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
   }
   else
   {
      fprintf(stderr, "Opened database successfully\n");
   }

   /* Create SQL statement */
   ss << "SELECT * from hvacdata;";
   string sql(ss.str());

   /* Execute SQL statement */
   //    rc = sqlite3_exec(db, sql, callback, (hvac*)datahvac, &zErrMsg);

   // compile sql statement to binary
   if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL) != SQLITE_OK)
   {
      fprintf(stderr, "ERROR: while compiling sql: %s\n", sqlite3_errmsg(db));
      sqlite3_close(db);
      sqlite3_finalize(stmt);
      // return found;
   }

   // execute sql statement, and while there are rows returned, print ID
   int ret_code = 0;
   // int i =0;
   for (int i = 0; i < 9; i++)
   {
      while ((ret_code = sqlite3_step(stmt)) == SQLITE_ROW)
      {
       //  fprintf(stderr, "TEST: ID = %d\n", sqlite3_column_int(stmt, i));
         // fprintf(stderr,"%d",sqlite3_column_int(stmt,i));
         // fprintf(stderr,"val %d\n",sqlite3_column_int(stmt,0));

         if (i == 0)
         {

            int db_Value = sqlite3_column_int(stmt, i);
            hd.defrost_front = to_string(db_Value);
           // fprintf(stderr, "db_Value....%d\n", db_Value);
            // fprintf(stderr,"def....%s\n",hd.defrost_front);
         }
         if (i == 1)
         {
            int db_Value = sqlite3_column_int(stmt, i);
            hd.defrost_rear = to_string(db_Value);
           // fprintf(stderr, "db_Value....%d\n", db_Value);
            // fprintf(stderr,"def....%s\n",hd.defrost_front);
         }
         if (i == 2)
         {
            int db_Value = sqlite3_column_int(stmt, i);
            hd.air_circulation = to_string(db_Value);
          //  fprintf(stderr, "db_Value....%d\n", db_Value);
            // fprintf(stderr,"def....%s\n",hd.defrost_front);
         }
         if (i == 3)
         {
            int db_Value = sqlite3_column_int(stmt, i);
            hd.ac_state_front = to_string(db_Value);
          //  fprintf(stderr, "db_Value....%d\n", db_Value);
            // fprintf(stderr,"def....%s\n",hd.defrost_front);
         }
         if (i == 4)
         {
            int db_Value = sqlite3_column_int(stmt, i);
            hd.ac_vent_flow_front = to_string(db_Value);
          //  fprintf(stderr, "db_Value....%d\n", db_Value);
            // fprintf(stderr,"def....%s\n",hd.defrost_front);
         }
         if (i == 5)
         {
            int db_Value = sqlite3_column_int(stmt, i);
            hd.temperature_front = to_string(db_Value);
           // fprintf(stderr, "db_Value....%d\n", db_Value);
            // fprintf(stderr,"def....%s\n",hd.defrost_front);
         }
         if (i == 6)
         {
            int db_Value = sqlite3_column_int(stmt, i);
            hd.ac_state_rear = to_string(db_Value);
           // fprintf(stderr, "db_Value....%d\n", db_Value);
            // fprintf(stderr,"def....%s\n",hd.defrost_front);
         }
         if (i == 7)
         {
            int db_Value = sqlite3_column_int(stmt, i);
            hd.ac_vent_flow_rear = to_string(db_Value);
            //fprintf(stderr, "db_Value....%d\n", db_Value);
            // fprintf(stderr,"def....%s\n",hd.defrost_front);
         }
         if (i == 8)
         {
            int db_Value = sqlite3_column_int(stmt, i);
            hd.temperature_rear = to_string(db_Value);
           // fprintf(stderr, "db_Value....%d\n", db_Value);
            // fprintf(stderr,"def....%s\n",hd.defrost_front);
         }
         // sm.defrost_front=db_Value;

         found = true;
      }
   }

   if (ret_code != SQLITE_DONE)
   {
      // this error handling could be done better, but it works
      fprintf(stderr, "ERROR: while performing sql: %s\n", sqlite3_errmsg(db));
      fprintf(stderr, "ret_code = %d\n", ret_code);
   }
    fprintf(stderr, "Operation done successfully\n");
   //fprintf(stderr, "entry %s\n", found ? "found" : "not found");

   // release resources
   // sqlite3_finalize(stmt);
   // sqlite3_close(db);

   //    if( rc != SQLITE_OK ) {
   //       fprintf(stderr, "SQL error: %s\n", zErrMsg);
   //       sqlite3_free(zErrMsg);
   //    } else {
   //       fprintf(stdout, "Operation done successfully\n");
   //    }
   sqlite3_free(zErrMsg);

   fprintf(stdout, "Operation done successfully\n");
   sqlite3_finalize(stmt);
   sqlite3_close(db);
}
void handle_request(
   http_request request,
   function<void(web::json::value const &, web::json::value &)> action)
   
{
   auto answer = web::json::value::object();
   TRACE("\nhanddle\n");
   request
      .extract_json()
      .then([&answer, &action](pplx::task<web::json::value> task) {
         try
         {
            auto const & jvalue = task.get();
            TRACE("\naction test\n");
            //display_json(jvalue);

            if (!jvalue.is_null())
            {
               TRACE("\ninside if\n");
               action(jvalue, answer);
            }
            else
            {
               TRACE("\nelse\n");
            }
         }
         catch (http_exception const & e)
         {
         //   wcout << e.what() << endl;
         TRACE("\nerror\n");
         }
      })
      .wait();

   
  // display_json(answer);
  TRACE("\ntesting\n");

   request.reply(status_codes::OK, answer);
}


void postRequest_Sample(http_request request)
{
   TRACE("\nhandle POST\n");

   //    request.reply(status_codes::OK, request.body());

   auto answer = json::value::object();

   request.extract_json().then([=](json::value body)
                               {
                                 // answer["0"] = json::value::string(body.at("first").as_string());

                                  json::value response;

                                  po.defrost_front = body.at("defrost_front").as_string();
                                  po.defrost_rear = body.at("defrost_rear").as_string();
                                  po.air_circulation = body.at("air_circulation").as_string();
                                  po.ac_state_front = body.at("ac_state_front").as_string();
                                  po.ac_vent_flow_front = body.at("ac_vent_flow_front").as_string();
                                  po.temperature_front = body.at("temperature_front").as_string();
                                  po.ac_state_rear = body.at("ac_state_rear").as_string();
                                  po.ac_vent_flow_rear = body.at("ac_vent_flow_rear").as_string();
                                  po.temperature_rear = body.at("temperature_rear").as_string();
                                  
                                  
                                  response["defrost_front"] = json::value::string(po.defrost_front);
                                  response["defrost_rear"] = json::value::string(po.defrost_rear);
                                  response["air_circulation"] = json::value::string(po.air_circulation);
                                  response["ac_state_front"] = json::value::string(po.ac_state_front);
                                  response["ac_vent_flow_front"] = json::value::string(po.ac_vent_flow_front);
                                  response["temperature_front"] = json::value::string(po.temperature_front);
                                  response["ac_state_rear"] = json::value::string(po.ac_state_rear);
                                  response["ac_vent_flow_rear"] = json::value::string(po.ac_vent_flow_rear);
                                  response["temperature_rear"] = json::value::string(po.temperature_rear);

                                  request.reply(status_codes::OK, response);



                               }).wait();

}

void getRequest_Sample(http_request getReqObj)
{

   pplx::task<web::json::value> tempTask = getReqObj.extract_json();
   tempTask.wait();
   web::json::value rcvData = tempTask.get();

   // sqlite get function
   getdatafromdb();
   auto response = from_json();

   // cout<<"data======"<<hd.defrost_front;

   // auto response = rcvData; // json::value::object();

   // response["first"] = json::value::string("Abcd");

   getReqObj.reply(status_codes::OK, response);
}
void trytogetapi()
{
  
   uri address_SampleRead("http://localhost:8080/restapi");

   http_listener listener(address_SampleRead);

   listener.support(methods::GET, &getRequest_Sample);
   listener.support(methods::POST, &postRequest_Sample);

   // listener_SampleRead.open().wait();

   // printf("\n ready \n");
   // while(true);
   // listener_SampleRead.close().wait();

   try
   {
      listener
          .open()
          .then([&listener]()
                { TRACE(L"\nstarting to listen\n"); })
          .wait();

      while (true)
         ;
   }
   catch (exception const &e)
   {
      wcout << e.what() << endl;
   }
}

int main(int argc, char **argv)
{

   std::thread thread_obj1(trytogetapi);
   thread_obj1.detach();

//    postData djd;
//   getpostdata(djd);
   //    cout<<" j is "<<i<<endl;
   //    signed int microsecond = 1000000;
   //    usleep(1 * microsecond);
   // }
   while (true)
   {
   }

   cout << "aaya" << endl;

   // eturn (0);
}

#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include "restSimulator.h"
#include <cpprest/http_client.h> 

using namespace web::http;
using namespace web::http::experimental::listener;
//using namespace web::json;

//ddsNode_RESTbridge* bridgeObjPtr;

nlohmann::json msg_HVACREAD_template=         						  {{"1",{
									                                        	{"messageId","message_temperature"},
									                                        	{"req","TEMPERATURE"},
									                                        	{"hvacTemperatureObj",{
									                                            	                    {"temp","17"},{"zone","all"}
									                                                	              }
									                                        	}
									                                       	}
									                                   },
									                                   {"2",{
									                                        	{"messageId","message_autoac"},
									                                        	{"req","AUTOAC"},
									                                        	{"hvacAutoAC",{
									                                        					{"status","true"}
									                                        				  }
									                                        	} 
									                                    	}
									                                    },
									                                   {"3",{
									                                        	{"messageId","message_defogger"},
									                                        	{"req","DEFOGGER"},
									                                        	{"hvacDefogger",{
									                                        						{"status","true"}
									                                        					}
									                                        	}
									                                    	}
									                                    },
									                                   {"4",{
									                                        	{"messageId","message_climate_flow_control"},
									                                        	{"req","CLIMATE_FLOW_CONTROL"}, 
									                                        	{"hvacClimateFlowControl",{
									                                        								{"enum","low"}
									                                        							  }
									                                        	}
									                                    	}
									                                    },
									                                   {"5",{
									                                        	{"messageId","message_fan_speed"},
									                                        	{"req","FAN_SPEED"},
									                                        	{"hvacFanSpeed",{
									                                        						{"enum","FAN_SPEED_1"}
									                                        					}
									                                        	}
									                                    	}
									                                	}};

nlohmann::json msg_HVACWRITE_template=							      {{"1",{
									                                        	{"messageId","message_temperature"},
									                                        	{"req","TEMPERATURE"},
									                                        	{"hvacTemperatureObj",{
									                                            	                    {"temp","17"},{"zone","all"}
									                                                	              }
									                                        	}
									                                       	}
									                                   },
									                                   {"2",{
									                                        	{"messageId","message_autoac"},
									                                        	{"req","AUTOAC"},
									                                        	{"hvacAutoAC",{
									                                        					{"status","true"}
									                                        				  }
									                                        	} 
									                                    	}
									                                    },
									                                   {"3",{
									                                        	{"messageId","message_defogger"},
									                                        	{"req","DEFOGGER"},
									                                        	{"hvacDefogger",{
									                                        						{"status","true"}
									                                        					}
									                                        	}
									                                    	}
									                                    },
									                                   {"4",{
									                                        	{"messageId","message_climate_flow_control"},
									                                        	{"req","CLIMATE_FLOW_CONTROL"}, 
									                                        	{"hvacClimateFlowControl",{
									                                        								{"enum","low"}
									                                        							  }
									                                        	}
									                                    	}
									                                    },
									                                   {"5",{
									                                        	{"messageId","message_fan_speed"},
									                                        	{"req","FAN_SPEED"},
									                                        	{"hvacFanSpeed",{
									                                        						{"enum","FAN_SPEED_1"}
									                                        					}
									                                        	}
									                                    	}
									                                	}};


nlohmann::json msg_HVAC_MQTT_SET_STATUS_template=					  {{"1",{
									                                        	{"messageId","message_temperature"},
									                                        	{"req","TEMPERATURE"},
									                                        	{"hvacTemperatureObj",{
									                                            	                    {"temp","17"},{"zone","all"}
									                                                	              }
									                                        	}
									                                       	}
									                                   },
									                                   {"2",{
									                                        	{"messageId","message_autoac"},
									                                        	{"req","AUTOAC"},
									                                        	{"hvacAutoAC",{
									                                        					{"status","true"}
									                                        				  }
									                                        	} 
									                                    	}
									                                    },
									                                   {"3",{
									                                        	{"messageId","message_defogger"},
									                                        	{"req","DEFOGGER"},
									                                        	{"hvacDefogger",{
									                                        						{"status","true"}
									                                        					}
									                                        	}
									                                    	}
									                                    },
									                                   {"4",{
									                                        	{"messageId","message_climate_flow_control"},
									                                        	{"req","CLIMATE_FLOW_CONTROL"}, 
									                                        	{"hvacClimateFlowControl",{
									                                        								{"enum","low"}
									                                        							  }
									                                        	}
									                                    	}
									                                    },
									                                   {"5",{
									                                        	{"messageId","message_fan_speed"},
									                                        	{"req","FAN_SPEED"},
									                                        	{"hvacFanSpeed",{
									                                        						{"enum","FAN_SPEED_1"}
									                                        					}
									                                        	}
									                                    	}
									                                	}};

web::json::value msg_HVACRESPONSE_template=web::json::value::parse(
															 "        {\"1\":{                                                                       "
									                         "                	\"messageId\":\"message_temperature\",                               "
									                         "               	\"req\":\"TEMPERATURE\",                                             "
									                         "               	\"hvacTemperatureObj\":{                                             "
									                         "                   	                    \"temp\":\"17\",\"zone\":\"all\"             "
									                         "                       	               }                                             "
									                         "                 },                                                                    "
									                         "          \"2\":{                                                                      "
									                         "               	\"messageId\":\"message_autoac\",                                    "
									                         "               	\"req\":\"AUTOAC\",                                                  "
									                         "               	\"hvacAutoAC\":{                                                     "
									                         "               					\"status\":\"true\"                                  "
									                         "               				    }                                                    "
									                         "               	},                                                                   "
									                         "          \"3\":{                                                                      "
									                         "               	\"messageId\":\"message_defogger\",                                  "
									                         "               	\"req\":\"DEFOGGER\",                                                "
									                         "               	\"hvacDefogger\":{                                                   "
									                         "               						\"status\":\"true\"                              "
									                         "               					  }                                                  "
									                         "               	},                                                                   "
									                         "          \"4\":{                                                                      "
									                         "               	\"messageId\":\"message_climate_flow_control\",                      "
									                         "               	\"req\":\"CLIMATE_FLOW_CONTROL\",                                    "
									                         "               	\"hvacClimateFlowControl\":{                                         "
									                         "               								\"enum\":\"low\"                         "
									                         "               							    }                                        "
									                         "               	},                                                                   "
									                         "          \"5\":{                                                                      "
									                         "               	\"messageId\":\"message_fan_speed\",                                 "
									                         "               	\"req\":\"FAN_SPEED\",                                               "
									                         "               	\"hvacFanSpeed\":{                                                   "
									                         "               						\"enum\":\"FAN_SPEED_1\"                         "
									                         "               					  }                                                  "
									                         "               	}}                                                                   "
									                         );

web::json::value msg_HVAC_MQTT_CURRENT_STATUS_template =web::json::value::parse(
															 "        {\"1\":{                                                                       "
									                         "                	\"messageId\":\"message_temperature\",                               "
									                         "               	\"req\":\"TEMPERATURE\",                                             "
									                         "               	\"hvacTemperatureObj\":{                                             "
									                         "                   	                    \"temp\":\"17\",\"zone\":\"all\"             "
									                         "                       	               }                                             "
									                         "                 },                                                                    "
									                         "          \"2\":{                                                                      "
									                         "               	\"messageId\":\"message_autoac\",                                    "
									                         "               	\"req\":\"AUTOAC\",                                                  "
									                         "               	\"hvacAutoAC\":{                                                     "
									                         "               					\"status\":\"true\"                                  "
									                         "               				    }                                                    "
									                         "               	},                                                                   "
									                         "          \"3\":{                                                                      "
									                         "               	\"messageId\":\"message_defogger\",                                  "
									                         "               	\"req\":\"DEFOGGER\",                                                "
									                         "               	\"hvacDefogger\":{                                                   "
									                         "               						\"status\":\"true\"                              "
									                         "               					  }                                                  "
									                         "               	},                                                                   "
									                         "          \"4\":{                                                                      "
									                         "               	\"messageId\":\"message_climate_flow_control\",                      "
									                         "               	\"req\":\"CLIMATE_FLOW_CONTROL\",                                    "
									                         "               	\"hvacClimateFlowControl\":{                                         "
									                         "               								\"enum\":\"low\"                         "
									                         "               							    }                                        "
									                         "               	},                                                                   "
									                         "          \"5\":{                                                                      "
									                         "               	\"messageId\":\"message_fan_speed\",                                 "
									                         "               	\"req\":\"FAN_SPEED\",                                               "
									                         "               	\"hvacFanSpeed\":{                                                   "
									                         "               						\"enum\":\"FAN_SPEED_1\"                         "
									                         "               					  }                                                  "
									                         "               	}}                                                                   "
									                         );

void getRequest_HVACREAD(http_request getReqObj);
void postRequest_HVACWRITE(http_request postReqObj);
void postRequest_HVAC_MQTT_SET_STATUS(http_request postReqObj);
void RestApplicationCbk_HVAC_MQTT_CURRENT_STATUS(nlohmann::json msg_HVAC_MQTT_CURRENT_STATUS);
void RestApplicationCbk_HVACRESPONSE(nlohmann::json msg_HVACRESPONSE);

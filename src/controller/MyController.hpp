#ifndef MyController_hpp
#define MyController_hpp

#include "dto/DTOs.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class MyController : public oatpp::web::server::api::ApiController {
    private:
        typedef MyController __ControllerType;
    
    public:
        MyController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
            : oatpp::web::server::api::ApiController(objectMapper) // initializer list for the base/parent class
        {}

        ENDPOINT_ASYNC("GET", "/hello", Root) {

            ENDPOINT_ASYNC_INIT(Root)

            Action act() override {
                auto dto = MessageDto::createShared();
                dto->statusCode = 200;
                dto->message = "Hello World Async!";

                return _return(controller->createDtoResponse(Status::CODE_200, dto));
            }
        };
};

#include OATPP_CODEGEN_END(ApiController)

#endif /* MyController_hpp */

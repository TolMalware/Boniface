#include <iostream>
#include <utility>
#include "MiddlewareManager.h"

Middleware * MiddlewareManager::compose(std::list<Middleware*> *middlewares) {
  auto it = middlewares->begin();
  if (middlewares->size()==1){
    return *middlewares->begin();
  }
  while (it != middlewares->end()) {
    Middleware* current = *it;
    it++;
    if (it==middlewares->end()){
      current->nextMiddleware =*it;
      break;
    }
    current->nextMiddleware = *it++;
  }
  return *middlewares->begin();
}

void MiddlewareManager::handleRequest(Context *context) {
  // TODO: error handling
  this->composedMiddleware->handle_request(context);
}

void MiddlewareManager::composeMiddleware() {
  this->composedMiddleware = MiddlewareManager::compose(this->middlewares);
}

MiddlewareManager::MiddlewareManager() {
  this->middlewares = new std::list<Middleware*>;
  this->composedMiddleware = new Middleware();
}

void Middleware::handle_request(Context *context) {
  handler(context);
  if (this->nextMiddleware != nullptr) {
    this->nextMiddleware->handle_request(context);
  }

}

Middleware::Middleware(MiddlewareFunc handler) {
  this->handler = std::move(handler);
  this->nextMiddleware = nullptr;
}

Middleware::Middleware() {
}

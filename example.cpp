#include <flow/flow.hpp>

std::string hello_world()
{
   return "Hello World";
}

void receive_message(std::string&& message)
{
   std::cout << "Received Message: " << message << "\n";
}

int main()
{
   using namespace std::literals;

   /**
    * The producer_impl hello_world is going to be publishing to the global std::string
    * multi_channel. The consumer receive_message is going to subscribe to the global std::string
    * multi_channel.
    */
   auto network = flow::network(hello_world, receive_message);

   /**
    * Note: cancellation begins in 2 seconds, but cancellation
    * is non-deterministic
    */
   network.cancel_after(1ms);

   flow::spin(std::move(network));
}

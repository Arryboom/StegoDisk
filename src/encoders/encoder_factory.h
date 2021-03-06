/**
* @file encoder_factory.h
* @author Martin Kosdy
* @author Matus Kysel
* @date 2016
* @brief Encoder factory
*
*/

#ifndef STEGODISK_ENCODERS_ENCODERFACTORY_H_
#define STEGODISK_ENCODERS_ENCODERFACTORY_H_

#include "encoder.h"

#include <memory>
#include <vector>

#include "stego-disk_export.h"

using namespace std;

namespace stego_disk {

class STEGO_DISK_EXPORT EncoderFactory final
{
private: 
  EncoderFactory();

public:

  enum class EncoderType {
    LSB,
    HAMMING
  };

  // Get vector of all encoders (each encoder with all possible settings)
  static vector<std::shared_ptr<Encoder>> GetAllEncoders();
  // Get vector of all encoders (each encoder once with default settings)
  static vector<std::shared_ptr<Encoder>> GetEncoders();
  // Get names of all encoders supported by this library
  static vector<string> GetEncoderNames();
  // Get instance of encoder based on the his type
  static std::shared_ptr<Encoder> GetEncoder(const EncoderType encoder);
  // set encoder param by name
  static void SetEncoderArg(std::shared_ptr<Encoder> encoder,
                                  const string &param, const string &val);
  // Get instance of the default encoder
  static std::shared_ptr<Encoder> GetDefaultEncoder();

  static EncoderType GetDefaultEncoderType();

  static EncoderType GetEncoderType(const std::string &encoder);

  static const std::string GetEncoderName(const EncoderType encoder);

private:
  static const EncoderType kDefaultEncoder = EncoderType::HAMMING;
};

} // stego_disk

#endif // STEGODISK_ENCODERS_ENCODERFACTORY_H_

#include <napi.h>
#include <cstring>

#include "mbedtls/ssl.h"
#include "mbedtls/error.h"

#include "Constants.h"

Napi::Value Constants::MbedtlsError(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	char buffer[ERROR_BUF_LEN];
	int errorno = info[0].IsNumber() ? info[0].As<Napi::Number>().Int32Value() : 0;
	mbedtls_strerror(errorno, buffer, ERROR_BUF_LEN);
	return ERROR_IS_KNOWN(buffer) ? Napi::String::New(env, buffer) : env.Undefined();
}

Napi::Object Constants::Initialize(Napi::Env env, Napi::Object exports) {
	/** error function */
	exports.Set("MbedtlsError", Napi::Function::New(env, Constants::MbedtlsError));

	/** Error codes */
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_FEATURE_UNAVAILABLE);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_BAD_INPUT_DATA);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_INVALID_MAC);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_INVALID_RECORD);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_CONN_EOF);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_UNKNOWN_CIPHER);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_NO_CIPHER_CHOSEN);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_NO_RNG);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_NO_CLIENT_CERTIFICATE);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_CERTIFICATE_TOO_LARGE);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_CERTIFICATE_REQUIRED);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_PRIVATE_KEY_REQUIRED);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_CA_CHAIN_REQUIRED);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_UNEXPECTED_MESSAGE);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_FATAL_ALERT_MESSAGE);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_PEER_VERIFY_FAILED);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_PEER_CLOSE_NOTIFY);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_BAD_HS_CLIENT_HELLO);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_BAD_HS_SERVER_HELLO);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_BAD_HS_CERTIFICATE);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_BAD_HS_CERTIFICATE_REQUEST);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_BAD_HS_SERVER_KEY_EXCHANGE);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_BAD_HS_SERVER_HELLO_DONE);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_BAD_HS_CLIENT_KEY_EXCHANGE);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_BAD_HS_CLIENT_KEY_EXCHANGE_RP);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_BAD_HS_CLIENT_KEY_EXCHANGE_CS);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_BAD_HS_CERTIFICATE_VERIFY);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_BAD_HS_CHANGE_CIPHER_SPEC);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_BAD_HS_FINISHED);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_ALLOC_FAILED);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_HW_ACCEL_FAILED);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_HW_ACCEL_FALLTHROUGH);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_COMPRESSION_FAILED);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_BAD_HS_PROTOCOL_VERSION);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_BAD_HS_NEW_SESSION_TICKET);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_SESSION_TICKET_EXPIRED);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_PK_TYPE_MISMATCH);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_UNKNOWN_IDENTITY);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_INTERNAL_ERROR);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_COUNTER_WRAPPING);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_WAITING_SERVER_HELLO_RENEGO);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_HELLO_VERIFY_REQUIRED);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_BUFFER_TOO_SMALL);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_NO_USABLE_CIPHERSUITE);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_WANT_READ);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_WANT_WRITE);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_TIMEOUT);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_CLIENT_RECONNECT);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_UNEXPECTED_RECORD);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_NON_FATAL);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_INVALID_VERIFY_HASH);
	EXPORT_CONST(exports, MBEDTLS_ERR_SSL_CONTINUE_PROCESSING);

	/** Various constants */
	EXPORT_CONST(exports, MBEDTLS_SSL_MAJOR_VERSION_3);
	EXPORT_CONST(exports, MBEDTLS_SSL_MINOR_VERSION_0);
	EXPORT_CONST(exports, MBEDTLS_SSL_MINOR_VERSION_1);
	EXPORT_CONST(exports, MBEDTLS_SSL_MINOR_VERSION_2);
	EXPORT_CONST(exports, MBEDTLS_SSL_MINOR_VERSION_3);

	EXPORT_CONST(exports, MBEDTLS_SSL_TRANSPORT_STREAM);
	EXPORT_CONST(exports, MBEDTLS_SSL_TRANSPORT_DATAGRAM);

	EXPORT_CONST(exports, MBEDTLS_SSL_MAX_HOST_NAME_LEN);

	/** RFC 6066 section 4, see also mfl_code_to_length in ssl_tls.c */
	/** NONE must be zero so that memset()ing structure to zero works */
	EXPORT_CONST(exports, MBEDTLS_SSL_MAX_FRAG_LEN_NONE);
	EXPORT_CONST(exports, MBEDTLS_SSL_MAX_FRAG_LEN_512);
	EXPORT_CONST(exports, MBEDTLS_SSL_MAX_FRAG_LEN_1024);
	EXPORT_CONST(exports, MBEDTLS_SSL_MAX_FRAG_LEN_2048);
	EXPORT_CONST(exports, MBEDTLS_SSL_MAX_FRAG_LEN_4096);
	EXPORT_CONST(exports, MBEDTLS_SSL_MAX_FRAG_LEN_INVALID);

	EXPORT_CONST(exports, MBEDTLS_SSL_IS_CLIENT);
	EXPORT_CONST(exports, MBEDTLS_SSL_IS_SERVER);

	EXPORT_CONST(exports, MBEDTLS_SSL_IS_NOT_FALLBACK);
	EXPORT_CONST(exports, MBEDTLS_SSL_IS_FALLBACK);

	EXPORT_CONST(exports, MBEDTLS_SSL_EXTENDED_MS_DISABLED);
	EXPORT_CONST(exports, MBEDTLS_SSL_EXTENDED_MS_ENABLED);

	EXPORT_CONST(exports, MBEDTLS_SSL_ETM_DISABLED);
	EXPORT_CONST(exports, MBEDTLS_SSL_ETM_ENABLED);

	EXPORT_CONST(exports, MBEDTLS_SSL_COMPRESS_NULL);
	EXPORT_CONST(exports, MBEDTLS_SSL_COMPRESS_DEFLATE);

	EXPORT_CONST(exports, MBEDTLS_SSL_VERIFY_NONE);
	EXPORT_CONST(exports, MBEDTLS_SSL_VERIFY_OPTIONAL);
	EXPORT_CONST(exports, MBEDTLS_SSL_VERIFY_REQUIRED);
	EXPORT_CONST(exports, MBEDTLS_SSL_VERIFY_UNSET);

	EXPORT_CONST(exports, MBEDTLS_SSL_LEGACY_RENEGOTIATION);
	EXPORT_CONST(exports, MBEDTLS_SSL_SECURE_RENEGOTIATION);

	EXPORT_CONST(exports, MBEDTLS_SSL_RENEGOTIATION_DISABLED);
	EXPORT_CONST(exports, MBEDTLS_SSL_RENEGOTIATION_ENABLED);

	EXPORT_CONST(exports, MBEDTLS_SSL_ANTI_REPLAY_DISABLED);
	EXPORT_CONST(exports, MBEDTLS_SSL_ANTI_REPLAY_ENABLED);

	EXPORT_CONST(exports, MBEDTLS_SSL_RENEGOTIATION_NOT_ENFORCED);
	EXPORT_CONST(exports, MBEDTLS_SSL_RENEGO_MAX_RECORDS_DEFAULT);

	EXPORT_CONST(exports, MBEDTLS_SSL_LEGACY_NO_RENEGOTIATION);
	EXPORT_CONST(exports, MBEDTLS_SSL_LEGACY_ALLOW_RENEGOTIATION);
	EXPORT_CONST(exports, MBEDTLS_SSL_LEGACY_BREAK_HANDSHAKE);

	EXPORT_CONST(exports, MBEDTLS_SSL_TRUNC_HMAC_DISABLED);
	EXPORT_CONST(exports, MBEDTLS_SSL_TRUNC_HMAC_ENABLED);
	EXPORT_CONST(exports, MBEDTLS_SSL_TRUNCATED_HMAC_LEN);

	EXPORT_CONST(exports, MBEDTLS_SSL_SESSION_TICKETS_DISABLED);
	EXPORT_CONST(exports, MBEDTLS_SSL_SESSION_TICKETS_ENABLED);

	EXPORT_CONST(exports, MBEDTLS_SSL_CBC_RECORD_SPLITTING_DISABLED);
	EXPORT_CONST(exports, MBEDTLS_SSL_CBC_RECORD_SPLITTING_ENABLED);

	EXPORT_CONST(exports, MBEDTLS_SSL_ARC4_ENABLED);
	EXPORT_CONST(exports, MBEDTLS_SSL_ARC4_DISABLED);

	EXPORT_CONST(exports, MBEDTLS_SSL_PRESET_DEFAULT);
	EXPORT_CONST(exports, MBEDTLS_SSL_PRESET_SUITEB);

	EXPORT_CONST(exports, MBEDTLS_SSL_CERT_REQ_CA_LIST_ENABLED);
	EXPORT_CONST(exports, MBEDTLS_SSL_CERT_REQ_CA_LIST_DISABLED);

	/** Default range for DTLS retransmission timer value, in milliseconds. */
	/** RFC 6347 4.2.4.1 says from 1 second to 60 seconds. */
	EXPORT_CONST(exports, MBEDTLS_SSL_DTLS_TIMEOUT_DFL_MIN);
	EXPORT_CONST(exports, MBEDTLS_SSL_DTLS_TIMEOUT_DFL_MAX);

	/** Overrideable in config header */
	EXPORT_CONST(exports, MBEDTLS_SSL_DEFAULT_TICKET_LIFETIME);

	/** Overrideable in config header, but be careful (see ssl.h) */
	EXPORT_CONST(exports, MBEDTLS_SSL_MAX_CONTENT_LEN);

	/** Note: will be 36 if MBEDTLS_SSL_PROTO_SSL3 is defined, defaults to 12 */
	EXPORT_CONST(exports, MBEDTLS_SSL_VERIFY_DATA_MAX_LEN);

	/** Signaling ciphersuite values (SCSV) */
	EXPORT_CONST(exports, MBEDTLS_SSL_EMPTY_RENEGOTIATION_INFO);
	EXPORT_CONST(exports, MBEDTLS_SSL_FALLBACK_SCSV_VALUE);

	/** Supported Signature and Hash algorithms (For TLS 1.2) */
	/** RFC 5246 section 7.4.1.4.1 */
	EXPORT_CONST(exports, MBEDTLS_SSL_HASH_NONE);
	EXPORT_CONST(exports, MBEDTLS_SSL_HASH_MD5);
	EXPORT_CONST(exports, MBEDTLS_SSL_HASH_SHA1);
	EXPORT_CONST(exports, MBEDTLS_SSL_HASH_SHA224);
	EXPORT_CONST(exports, MBEDTLS_SSL_HASH_SHA256);
	EXPORT_CONST(exports, MBEDTLS_SSL_HASH_SHA384);
	EXPORT_CONST(exports, MBEDTLS_SSL_HASH_SHA512);

	EXPORT_CONST(exports, MBEDTLS_SSL_SIG_ANON);
	EXPORT_CONST(exports, MBEDTLS_SSL_SIG_RSA);
	EXPORT_CONST(exports, MBEDTLS_SSL_SIG_ECDSA);

	/** Client Certificate Types */
	/** RFC 5246 section 7.4.4 plus RFC 4492 section 5.5 */
	EXPORT_CONST(exports, MBEDTLS_SSL_CERT_TYPE_RSA_SIGN);
	EXPORT_CONST(exports, MBEDTLS_SSL_CERT_TYPE_ECDSA_SIGN);

	/** Message, alert and handshake types */
	EXPORT_CONST(exports, MBEDTLS_SSL_MSG_CHANGE_CIPHER_SPEC);
	EXPORT_CONST(exports, MBEDTLS_SSL_MSG_ALERT);
	EXPORT_CONST(exports, MBEDTLS_SSL_MSG_HANDSHAKE);
	EXPORT_CONST(exports, MBEDTLS_SSL_MSG_APPLICATION_DATA);

	EXPORT_CONST(exports, MBEDTLS_SSL_ALERT_LEVEL_WARNING);
	EXPORT_CONST(exports, MBEDTLS_SSL_ALERT_LEVEL_FATAL);

	EXPORT_CONST(exports, MBEDTLS_SSL_ALERT_MSG_CLOSE_NOTIFY);
	EXPORT_CONST(exports, MBEDTLS_SSL_ALERT_MSG_UNEXPECTED_MESSAGE);
	EXPORT_CONST(exports, MBEDTLS_SSL_ALERT_MSG_BAD_RECORD_MAC);
	EXPORT_CONST(exports, MBEDTLS_SSL_ALERT_MSG_DECRYPTION_FAILED);
	EXPORT_CONST(exports, MBEDTLS_SSL_ALERT_MSG_RECORD_OVERFLOW);
	EXPORT_CONST(exports, MBEDTLS_SSL_ALERT_MSG_DECOMPRESSION_FAILURE);
	EXPORT_CONST(exports, MBEDTLS_SSL_ALERT_MSG_HANDSHAKE_FAILURE);
	EXPORT_CONST(exports, MBEDTLS_SSL_ALERT_MSG_NO_CERT);
	EXPORT_CONST(exports, MBEDTLS_SSL_ALERT_MSG_BAD_CERT);
	EXPORT_CONST(exports, MBEDTLS_SSL_ALERT_MSG_UNSUPPORTED_CERT);
	EXPORT_CONST(exports, MBEDTLS_SSL_ALERT_MSG_CERT_REVOKED);
	EXPORT_CONST(exports, MBEDTLS_SSL_ALERT_MSG_CERT_EXPIRED);
	EXPORT_CONST(exports, MBEDTLS_SSL_ALERT_MSG_CERT_UNKNOWN);
	EXPORT_CONST(exports, MBEDTLS_SSL_ALERT_MSG_ILLEGAL_PARAMETER);
	EXPORT_CONST(exports, MBEDTLS_SSL_ALERT_MSG_UNKNOWN_CA);
	EXPORT_CONST(exports, MBEDTLS_SSL_ALERT_MSG_ACCESS_DENIED);
	EXPORT_CONST(exports, MBEDTLS_SSL_ALERT_MSG_DECODE_ERROR);
	EXPORT_CONST(exports, MBEDTLS_SSL_ALERT_MSG_DECRYPT_ERROR);
	EXPORT_CONST(exports, MBEDTLS_SSL_ALERT_MSG_EXPORT_RESTRICTION);
	EXPORT_CONST(exports, MBEDTLS_SSL_ALERT_MSG_PROTOCOL_VERSION);
	EXPORT_CONST(exports, MBEDTLS_SSL_ALERT_MSG_INSUFFICIENT_SECURITY);
	EXPORT_CONST(exports, MBEDTLS_SSL_ALERT_MSG_INTERNAL_ERROR);
	EXPORT_CONST(exports, MBEDTLS_SSL_ALERT_MSG_INAPROPRIATE_FALLBACK);
	EXPORT_CONST(exports, MBEDTLS_SSL_ALERT_MSG_USER_CANCELED);
	EXPORT_CONST(exports, MBEDTLS_SSL_ALERT_MSG_NO_RENEGOTIATION);
	EXPORT_CONST(exports, MBEDTLS_SSL_ALERT_MSG_UNSUPPORTED_EXT);
	EXPORT_CONST(exports, MBEDTLS_SSL_ALERT_MSG_UNRECOGNIZED_NAME);
	EXPORT_CONST(exports, MBEDTLS_SSL_ALERT_MSG_UNKNOWN_PSK_IDENTITY);
	EXPORT_CONST(exports, MBEDTLS_SSL_ALERT_MSG_NO_APPLICATION_PROTOCOL);

	EXPORT_CONST(exports, MBEDTLS_SSL_HS_HELLO_REQUEST);
	EXPORT_CONST(exports, MBEDTLS_SSL_HS_CLIENT_HELLO);
	EXPORT_CONST(exports, MBEDTLS_SSL_HS_SERVER_HELLO);
	EXPORT_CONST(exports, MBEDTLS_SSL_HS_HELLO_VERIFY_REQUEST);
	EXPORT_CONST(exports, MBEDTLS_SSL_HS_NEW_SESSION_TICKET);
	EXPORT_CONST(exports, MBEDTLS_SSL_HS_CERTIFICATE);
	EXPORT_CONST(exports, MBEDTLS_SSL_HS_SERVER_KEY_EXCHANGE);
	EXPORT_CONST(exports, MBEDTLS_SSL_HS_CERTIFICATE_REQUEST);
	EXPORT_CONST(exports, MBEDTLS_SSL_HS_SERVER_HELLO_DONE);
	EXPORT_CONST(exports, MBEDTLS_SSL_HS_CERTIFICATE_VERIFY);
	EXPORT_CONST(exports, MBEDTLS_SSL_HS_CLIENT_KEY_EXCHANGE);
	EXPORT_CONST(exports, MBEDTLS_SSL_HS_FINISHED);

	/** TLS extensions */
	EXPORT_CONST(exports, MBEDTLS_TLS_EXT_SERVERNAME);
	EXPORT_CONST(exports, MBEDTLS_TLS_EXT_SERVERNAME_HOSTNAME);
	EXPORT_CONST(exports, MBEDTLS_TLS_EXT_MAX_FRAGMENT_LENGTH);
	EXPORT_CONST(exports, MBEDTLS_TLS_EXT_TRUNCATED_HMAC);
	EXPORT_CONST(exports, MBEDTLS_TLS_EXT_SUPPORTED_ELLIPTIC_CURVES);
	EXPORT_CONST(exports, MBEDTLS_TLS_EXT_SUPPORTED_POINT_FORMATS);
	EXPORT_CONST(exports, MBEDTLS_TLS_EXT_SIG_ALG);
	EXPORT_CONST(exports, MBEDTLS_TLS_EXT_ALPN);
	EXPORT_CONST(exports, MBEDTLS_TLS_EXT_ENCRYPT_THEN_MAC);
	EXPORT_CONST(exports, MBEDTLS_TLS_EXT_EXTENDED_MASTER_SECRET);
	EXPORT_CONST(exports, MBEDTLS_TLS_EXT_SESSION_TICKET);
	EXPORT_CONST(exports, MBEDTLS_TLS_EXT_ECJPAKE_KKPP);
	EXPORT_CONST(exports, MBEDTLS_TLS_EXT_RENEGOTIATION_INFO);

	EXPORT_CONST(exports, MBEDTLS_PSK_MAX_LEN);
	EXPORT_CONST(exports, MBEDTLS_PREMASTER_SIZE);

	return exports;
}

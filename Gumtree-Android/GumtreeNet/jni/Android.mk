#
# Android.mk
#
# POCO HTTP Client
#

LOCAL_PATH  := $(call my-dir)

POCO_ROOT   := $(shell (cd $(LOCAL_PATH)/../../../poco-1.6.0 && pwd))
GUMTREENET_ROOT := $(shell (cd $(LOCAL_PATH)/../../../GumtreeNet && pwd))
$(info "LOCAL_PATH=$(LOCAL_PATH)")
$(info "POCO_ROOT=$(POCO_ROOT)")
$(info "GUMTREENET_ROOT=$(GUMTREENET_ROOT)")


####################################################################################################
include $(CLEAR_VARS)

POCO_FOUNDATION_ROOT    := $(POCO_ROOT)/Foundation

LOCAL_MODULE     := PocoFoundation
LOCAL_PATH       := $(POCO_FOUNDATION_ROOT)/src
LOCAL_CFLAGS     := -DPOCO_ANDROID -DPOCO_NO_FPENVIRONMENT -DPOCO_NO_WSTRING -DPOCO_NO_SHAREDMEMORY
LOCAL_CPPFLAGS   := -frtti -fexceptions
LOCAL_LDFLAGS    := -lc -ldl
LOCAL_C_INCLUDES := $(POCO_FOUNDATION_ROOT)/include

LOCAL_SRC_FILES := \
    ArchiveStrategy.cpp Ascii.cpp ASCIIEncoding.cpp AsyncChannel.cpp \
    Base32Decoder.cpp Base32Encoder.cpp Base64Decoder.cpp Base64Encoder.cpp \
    BinaryReader.cpp BinaryWriter.cpp Bugcheck.cpp ByteOrder.cpp Channel.cpp Checksum.cpp Clock.cpp Configurable.cpp ConsoleChannel.cpp \
    Condition.cpp CountingStream.cpp DateTime.cpp LocalDateTime.cpp DateTimeFormat.cpp DateTimeFormatter.cpp DateTimeParser.cpp \
    Debugger.cpp DeflatingStream.cpp DigestEngine.cpp DigestStream.cpp DirectoryIterator.cpp DirectoryWatcher.cpp \
    Environment.cpp Event.cpp Error.cpp EventArgs.cpp ErrorHandler.cpp Exception.cpp FIFOBufferStream.cpp FPEnvironment.cpp File.cpp \
    FileChannel.cpp Formatter.cpp FormattingChannel.cpp Glob.cpp HexBinaryDecoder.cpp LineEndingConverter.cpp \
    HexBinaryEncoder.cpp InflatingStream.cpp Latin1Encoding.cpp Latin2Encoding.cpp Latin9Encoding.cpp LogFile.cpp \
    Logger.cpp LoggingFactory.cpp LoggingRegistry.cpp LogStream.cpp NamedEvent.cpp NamedMutex.cpp NullChannel.cpp \
    MemoryPool.cpp MD4Engine.cpp MD5Engine.cpp Manifest.cpp Message.cpp Mutex.cpp \
    NestedDiagnosticContext.cpp Notification.cpp NotificationCenter.cpp \
    NotificationQueue.cpp PriorityNotificationQueue.cpp TimedNotificationQueue.cpp \
    NullStream.cpp NumberFormatter.cpp NumberParser.cpp NumericString.cpp AbstractObserver.cpp \
    Path.cpp PatternFormatter.cpp Process.cpp PurgeStrategy.cpp RWLock.cpp Random.cpp RandomStream.cpp \
    DirectoryIteratorStrategy.cpp RegularExpression.cpp RefCountedObject.cpp Runnable.cpp RotateStrategy.cpp \
    SHA1Engine.cpp Semaphore.cpp SharedLibrary.cpp SimpleFileChannel.cpp \
    SignalHandler.cpp SplitterChannel.cpp SortedDirectoryIterator.cpp Stopwatch.cpp StreamChannel.cpp \
    StreamConverter.cpp StreamCopier.cpp StreamTokenizer.cpp String.cpp StringTokenizer.cpp SynchronizedObject.cpp \
    Task.cpp TaskManager.cpp TaskNotification.cpp TeeStream.cpp Hash.cpp HashStatistic.cpp \
    TemporaryFile.cpp TextConverter.cpp TextEncoding.cpp TextIterator.cpp TextBufferIterator.cpp Thread.cpp ThreadLocal.cpp \
    ThreadPool.cpp ThreadTarget.cpp ActiveDispatcher.cpp Timer.cpp Timespan.cpp Timestamp.cpp Timezone.cpp Token.cpp URI.cpp \
    FileStreamFactory.cpp URIStreamFactory.cpp URIStreamOpener.cpp UTF32Encoding.cpp UTF16Encoding.cpp UTF8Encoding.cpp UTF8String.cpp \
    Unicode.cpp UnicodeConverter.cpp Windows1250Encoding.cpp Windows1251Encoding.cpp Windows1252Encoding.cpp \
    UUID.cpp UUIDGenerator.cpp Void.cpp Var.cpp VarHolder.cpp VarIterator.cpp Format.cpp Pipe.cpp PipeImpl.cpp PipeStream.cpp SharedMemory.cpp \
    MemoryStream.cpp FileStream.cpp AtomicCounter.cpp

LOCAL_SRC_FILES += \
    adler32.c compress.c crc32.c deflate.c \
    infback.c inffast.c inflate.c inftrees.c trees.c zutil.c

LOCAL_SRC_FILES += \
    pcre_config.c pcre_chartables.c pcre_compile.c pcre_globals.c pcre_maketables.c \
	pcre_study.c pcre_byte_order.c pcre_valid_utf8.c pcre_dfa_exec.c pcre_get.c pcre_jit_compile.c \
	pcre_exec.c pcre_ord2utf8.c pcre_newline.c pcre_fullinfo.c pcre_xclass.c pcre_refcount.c pcre_string_utils.c \
	pcre_version.c

LOCAL_SRC_FILES += pcre_ucd.c pcre_tables.c

LOCAL_SRC_FILES += SyslogChannel.cpp

include $(BUILD_SHARED_LIBRARY)

####################################################################################################
include $(CLEAR_VARS)

POCO_NET_ROOT    := $(POCO_ROOT)/Net

LOCAL_MODULE    := PocoNet

LOCAL_PATH      := $(POCO_NET_ROOT)/src
#LOCAL_STATIC_LIBRARIES := PocoFoundation
LOCAL_SHARED_LIBRARIES := PocoFoundation

LOCAL_CFLAGS     := -fpic -ffunction-sections -funwind-tables -fstack-protector -fno-strict-aliasing -finline-limit=64
LOCAL_CFLAGS     += -DPOCO_ANDROID -DPOCO_NO_FPENVIRONMENT -DPOCO_NO_WSTRING -DPOCO_NO_SHAREDMEMORY
LOCAL_CPPFLAGS   := $(LOCAL_CFLAGS) -frtti -fexceptions
LOCAL_C_INCLUDES := $(POCO_NET_ROOT)/include

LOCAL_C_INCLUDES    += $(POCO_ROOT)/Foundation/include

LOCAL_SRC_FILES := \
    Net.cpp DNS.cpp HTTPResponse.cpp HostEntry.cpp Socket.cpp \
	DatagramSocket.cpp HTTPServer.cpp IPAddress.cpp IPAddressImpl.cpp SocketAddress.cpp SocketAddressImpl.cpp \
	HTTPBasicCredentials.cpp HTTPCookie.cpp HTMLForm.cpp MediaType.cpp DialogSocket.cpp \
	DatagramSocketImpl.cpp FilePartSource.cpp HTTPServerConnection.cpp MessageHeader.cpp \
	HTTPChunkedStream.cpp HTTPServerConnectionFactory.cpp MulticastSocket.cpp SocketStream.cpp \
	HTTPClientSession.cpp HTTPServerParams.cpp MultipartReader.cpp StreamSocket.cpp SocketImpl.cpp \
	HTTPHeaderStream.cpp HTTPServerResponse.cpp HTTPServerResponseImpl.cpp NameValueCollection.cpp TCPServer.cpp \
	HTTPMessage.cpp HTTPServerSession.cpp NetException.cpp TCPServerConnection.cpp HTTPBufferAllocator.cpp \
	HTTPAuthenticationParams.cpp HTTPCredentials.cpp HTTPDigestCredentials.cpp \
	HTTPRequest.cpp HTTPSession.cpp HTTPSessionInstantiator.cpp HTTPSessionFactory.cpp NetworkInterface.cpp  \
	HTTPRequestHandler.cpp HTTPStream.cpp HTTPIOStream.cpp ServerSocket.cpp TCPServerDispatcher.cpp TCPServerConnectionFactory.cpp \
	HTTPRequestHandlerFactory.cpp HTTPStreamFactory.cpp ServerSocketImpl.cpp TCPServerParams.cpp \
	QuotedPrintableEncoder.cpp QuotedPrintableDecoder.cpp StringPartSource.cpp \
	FTPClientSession.cpp FTPStreamFactory.cpp PartHandler.cpp PartSource.cpp PartStore.cpp NullPartHandler.cpp \
	SocketReactor.cpp SocketNotifier.cpp SocketNotification.cpp AbstractHTTPRequestHandler.cpp \
	MailRecipient.cpp MailMessage.cpp MailStream.cpp SMTPClientSession.cpp POP3ClientSession.cpp\
	RawSocket.cpp RawSocketImpl.cpp ICMPClient.cpp ICMPEventArgs.cpp ICMPPacket.cpp ICMPPacketImpl.cpp \
	ICMPSocket.cpp ICMPSocketImpl.cpp ICMPv4PacketImpl.cpp \
	NTPClient.cpp NTPEventArgs.cpp NTPPacket.cpp \
	RemoteSyslogChannel.cpp RemoteSyslogListener.cpp SMTPChannel.cpp \
	WebSocket.cpp WebSocketImpl.cpp \
	OAuth10Credentials.cpp OAuth20Credentials.cpp

LOCAL_SRC_FILES += StreamSocketImpl.cpp \
    HTTPServerRequestImpl.cpp \
    HTTPFixedLengthStream.cpp \
    MultipartWriter.cpp \
    HTTPServerRequest.cpp



include $(BUILD_SHARED_LIBRARY)


####################################################################################################

include $(CLEAR_VARS)


LOCAL_MODULE    := PocoJSON

LOCAL_PATH      := $(POCO_ROOT)/JSON/src

LOCAL_CFLAGS     := -DPOCO_ANDROID -DPOCO_NO_FPENVIRONMENT -DPOCO_NO_WSTRING -DPOCO_NO_SHAREDMEMORY
LOCAL_CPPFLAGS   := -frtti -fexceptions

LOCAL_SHARED_LIBRARIES := PocoFoundation

LOCAL_C_INCLUDES := $(POCO_ROOT)/JSON/include
LOCAL_C_INCLUDES += $(POCO_ROOT)/Foundation/include

LOCAL_SRC_FILES  := \
   Array.cpp \
   Handler.cpp \
   JSONException.cpp \
   Object.cpp \
   ParseHandler.cpp \
   Parser.cpp \
   PrintHandler.cpp \
   Query.cpp \
   Stringifier.cpp \
   Template.cpp \
   TemplateCache.cpp


include $(BUILD_SHARED_LIBRARY)

####################################################################################################

include $(CLEAR_VARS)


LOCAL_MODULE    := GumtreeNet

LOCAL_PATH      := $(GUMTREENET_ROOT)/GumtreeNet

LOCAL_CFLAGS     := -DPOCO_ANDROID -DPOCO_NO_FPENVIRONMENT -DPOCO_NO_WSTRING -DPOCO_NO_SHAREDMEMORY
LOCAL_CPPFLAGS   := -frtti -fexceptions

LOCAL_SHARED_LIBRARIES := PocoFoundation PocoJSON PocoNet

LOCAL_C_INCLUDES := $(POCO_ROOT)/JSON/include
LOCAL_C_INCLUDES += $(POCO_ROOT)/Foundation/include
LOCAL_C_INCLUDES += $(POCO_ROOT)/Net/include

LOCAL_SRC_FILES  := \
   GTAd.cpp \
   GTAdPage.cpp \
   GTAdQuery.cpp \
   GTAdQueryRequest.cpp \
   GTAdQueryResponse.cpp \
   GumtreeClient.cpp \
   gumtreenet_wrap.cxx


include $(BUILD_SHARED_LIBRARY)

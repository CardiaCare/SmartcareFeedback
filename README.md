# SmartcareFeedback

<h2>Native</h2>

public native long connectSmartSpace(String name, String ip, int port) - подключение к узла ИП

public native void disconnectSmartSpace(long nodeDescriptor) — отключение от узла ИП

public native Feedback  getFeedback(long nodeDescriptor) - получение ответника из ИП

public native String initPatient (long nodeDescriptor) - получение пациента от узла ИП

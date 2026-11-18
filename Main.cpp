#include <jni.h>
#include <string>
#include "Includes/obfuscate.h"
#include "Menu/Menu.h"

// Menüdeki özelliklerin durumunu tutan değişkenler
bool isFeature1 = false;
int sliderValue = 1;

// Menü Başlığı ve Alt Başlığı
extern "C"
JNIEXPORT jstring JNICALL
Java_com_android_support_Menu_Title(JNIEnv *env, jobject thiz) {
    return env->NewStringUTF(OBFUSCATE("Özel Mod Menü"));
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_android_support_Menu_Heading(JNIEnv *env, jobject thiz) {
    return env->NewStringUTF(OBFUSCATE("v1.0 - Test Sürümü"));
}

// Kayan İkon (Base64 formatında PNG verisi buraya eklenir)
extern "C"
JNIEXPORT jstring JNICALL
Java_com_android_support_Menu_Icon(JNIEnv *env, jobject thiz) {
    return env->NewStringUTF(OBFUSCATE("BASE64_IKON_KODU_BURAYA"));
}

// Menü İçeriği (Butonlar, Kategoriler, Kaydırıcılar)
extern "C"
JNIEXPORT jobjectArray JNICALL
Java_com_android_support_Menu_GetFeatureList(JNIEnv *env, jobject context) {
    jobjectArray ret;

    const char *features[] = {
            OBFUSCATE("Category_Genel Ayarlar"),
            OBFUSCATE("0_Toggle_Özellik 1"),
            OBFUSCATE("1_SeekBar_Değer Ayarı_1_100"),
            OBFUSCATE("2_Button_Test Butonu"),
            OBFUSCATE("Category_Diğer"),
            OBFUSCATE("3_CheckBox_Onay Kutusu")
    };

    int Total_Feature = (sizeof features / sizeof features[0]);
    ret = (jobjectArray) env->NewObjectArray(Total_Feature, env->FindClass(OBFUSCATE("java/lang/String")), env->NewStringUTF(""));

    for (int i = 0; i < Total_Feature; i++) {
        env->SetObjectArrayElement(ret, i, env->NewStringUTF(features[i]));
    }
    return ret;
}

// Kullanıcı menüde bir değişiklik yaptığında çalışan fonksiyon
extern "C"
JNIEXPORT void JNICALL
Java_com_android_support_Preferences_Changes(JNIEnv *env, jclass clazz, jobject obj,
                                            jint featNum, jstring featName, jint value,
                                            jboolean boolean, jstring str) {
    switch (featNum) {
        case 0:
            isFeature1 = boolean;
            break;
        case 1:
            sliderValue = value;
            break;
        case 2:
            // Butona tıklandığında yapılacak işlem
            break;
        case 3:
            // CheckBox durumu
            break;
    }
}

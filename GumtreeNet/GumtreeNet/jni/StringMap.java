/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.6
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.gumtree.jni;

public class StringMap {
  private long swigCPtr;
  protected boolean swigCMemOwn;

  protected StringMap(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(StringMap obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        GumtreeNetJNI.delete_StringMap(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public StringMap() {
    this(GumtreeNetJNI.new_StringMap__SWIG_0(), true);
  }

  public StringMap(StringMap arg0) {
    this(GumtreeNetJNI.new_StringMap__SWIG_1(StringMap.getCPtr(arg0), arg0), true);
  }

  public long size() {
    return GumtreeNetJNI.StringMap_size(swigCPtr, this);
  }

  public boolean empty() {
    return GumtreeNetJNI.StringMap_empty(swigCPtr, this);
  }

  public void clear() {
    GumtreeNetJNI.StringMap_clear(swigCPtr, this);
  }

  public String get(String key) {
    return GumtreeNetJNI.StringMap_get(swigCPtr, this, key);
  }

  public void set(String key, String x) {
    GumtreeNetJNI.StringMap_set(swigCPtr, this, key, x);
  }

  public void del(String key) {
    GumtreeNetJNI.StringMap_del(swigCPtr, this, key);
  }

  public boolean has_key(String key) {
    return GumtreeNetJNI.StringMap_has_key(swigCPtr, this, key);
  }

}
#pragma once
#include <QtCore/qglobal.h>

#define JIN_NAMESPACE XmlUtils_JIN
#  define JIN_BEGIN_NAMESPACE namespace JIN_NAMESPACE {
#  define JIN_END_NAMESPACE }
#  define JIN_USE_NAMESPACE using namespace JIN_NAMESPACE;


# if defined(XMLUTILS_LIB)
#  define XMLUTILS_LIB_EXPORT Q_DECL_EXPORT
# else
#  define XMLUTILS_LIB_EXPORT Q_DECL_IMPORT
# endif

JIN_BEGIN_NAMESPACE

#define J_DELETE_AND_NULL(x) { if(x){delete x; x = nullptr;} }
#define J_DELETEER_AND_NULL(x) { if(x){x->deleteLater(); x = nullptr;} }
#define J_DECLARE_PRIVATE(Class) friend class Class##Private; \
Class##Private *qtn_d_ptr; \
Class##Private& qtn_d() { return *qtn_d_ptr; } \
const Class##Private& qtn_d() const { return *qtn_d_ptr; }

#define J_DECLARE_PUBLIC(Class) \
friend class Class; \
Class *qtn_p_ptr; \
inline void setPublic(Class *ptr) { qtn_p_ptr = ptr; } \
Class& qtn_p() { return *qtn_p_ptr; } \
const Class& qtn_p() const { return *qtn_p_ptr; }
#define J_INIT_PRIVATE(Class) \
qtn_d_ptr = new Class##Private(); qtn_d_ptr->setPublic(this);
#define J_D(Class) Class##Private& d = qtn_d();
#define J_P(Class) Class& p = qtn_p();
#define J_FINI_PRIVATE() \
delete qtn_d_ptr; qtn_d_ptr = nullptr;

#define J_DECLARE_EX_PRIVATE(Class) friend class Class##Private; \
Class##Private& qtn_d() { return reinterpret_cast<Class##Private &>(*qtn_d_ptr); } \
const Class##Private& qtn_d() const { return reinterpret_cast<const Class##Private &>(*qtn_d_ptr); }

#define J_DECLARE_EX_PUBLIC(Class) \
friend class Class; \
Class& qtn_p() { return static_cast<Class &>(*qtn_p_ptr); } \
const Class& qtn_p() const { return static_cast<Class &>(*qtn_p_ptr); }

JIN_END_NAMESPACE
JIN_USE_NAMESPACE




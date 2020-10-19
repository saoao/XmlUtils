#pragma once
#include <QObject>
#include "XmlUtilsGlobal.h"
#include <QtXml>
#include <QDir>

JIN_BEGIN_NAMESPACE

class XMLUTILS_LIB_EXPORT XmlUtils
{
public:
	/**
	 * Adds an XML node
	 *
	 * \param [in]	   dom			   the xml dom.
	 * \param [in]	   parentNodeName  ���ڵ�.
	 * \param [in]	   nodeName		   ��ǰ�ڵ�����.
	 * \param [in]	   attrNames	   List of names of the attributes.
	 * \param [in]	   attrs		   The attributes.
	 * \param [in]	   matchedAttrName ��Ҫ����ƥ�����������.
	 * \param [in]	   matchedContent  ��Ҫ����ƥ�������ֵ.
	 *
	 * \returns A QDomElement.
	 */

	static QDomElement addXmlNode(QDomDocument *dom,
		const QString & parentNodeName,
		const QString & nodeName,
		QStringList attrNames,
		QStringList attrs,
		const QString &matchedAttrName,
		const QString & matchedContent);

	/**
	 * Adds an XML node
	 *
	 * \param [in]	   dom			   the xml dom.
	 * \param [in]	   parentNodeName  ���ڵ�.
	 * \param [in]	   nodeName		   ��ǰ�ڵ�����.
	 * \param [in]	   attrNames	   List of names of the attributes.
	 * \param [in]	   attrs		   The attributes.
	 *
	 * \returns A QDomElement.
	 */

	static QDomElement addXmlNode(QDomDocument *dom,
		const QString & parentNodeName,
		const QString & nodeName,
		QStringList attrNames,
		QStringList attrs);

	/**
	 * Adds an text XML node
	 *
	 * \param [in]	   dom			   the xml dom.
	 * \param [in]	   parentNodeName  ���ڵ�.
	 * \param [in]	   nodeName		   ��ǰ�ڵ�����.
	 * \param [in]	   nodeText	       �ڵ��ı�ֵ.
	 *
	 * \returns A QDomElement.
	 */

	static QDomElement addXmlNode(QDomDocument *dom,
		const QString & parentNodeName,
		const QString & nodeName,
		const QString & nodeText);

	/**
	 * Adds an text XML node
	 *
	 * \param [in]	   dom			   the xml dom.
	 * \param [in]	   parentNodeName  ���ڵ�.
	 * \param [in]	   nodeName		   ��ǰ�ڵ�����.
	 * \param [in]	   nodeText	       �ڵ��ı�ֵ.
	 * \param [in]	   matchedAttrName ��Ҫ����ƥ�����������.
	 * \param [in]	   matchedContent  ��Ҫ����ƥ�������ֵ.
	 *
	 * \returns A QDomElement.
	 */

	static QDomElement addXmlNode(QDomDocument *dom,
		const QString & parentNodeName,
		const QString & nodeName,
		const QString & nodeText,
		const QString & matchedNodeName,
		const QString & name);

	/**
	 * Adds an XML node attribute
	 *
	 * \param [in]	   dom			   the xml dom.
	 * \param [in]	   parentNodeName  ���ڵ�.
	 * \param [in]	   nodeName		   ��ǰ�ڵ�����.
	 * \param [in]	   attrName	       ������.
	 * \param [in]	   attr			   ����ֵ.
	 */

	static void addXmlNodeAttr(QDomDocument * dom, const QString & nodeName,
		const QString &attrName, const QString &attr);

	/**
	 * Adds an XML node text
	 *
	 * \param [in]	   dom			   the xml dom.
	 * \param [in]	   parentNodeName  ���ڵ�.
	 * \param [in]	   nodeName		   ��ǰ�ڵ�����.
	 * \param [in]	   text			   �ı�.
	 */

	static void addXmlNodeText(QDomDocument * dom,
		const QString & nodeName, const QString &text);

	/**
	 * ����һ���սڵ㡣û�����Ժ��ı�
	 *
	 * \param [in]     dom	          the xml dom.
	 * \param [in]	   parentNodeName ���ڵ�.
	 * \param [in]	   nodeName	      �ڵ�����.
	 *
	 * \returns A nil QDomElement.
	 */

	static QDomElement addOneNilNode(QDomDocument * dom, const QString & parentNodeName,
		const QString & nodeName);

	/**
	 * Adds an one nil node
	 *
	 * \param [in]     dom	           the xml dom.
	 * \param [in]	   parentNodeName  ���ڵ�.
	 * \param [in]	   nodeName	       �ڵ�����.
	 * \param [in]	   matchedAttrName ��Ҫ����ƥ�����������.
	 * \param [in]	   matchedContent  ��Ҫ����ƥ�������ֵ.
	 *
	 * \returns A nil QDomElement.
	 */

	static QDomElement addOneNilNode(QDomDocument * dom,
		const QString & _parentNodeName,
		const QString & _nodeName,
		const QString & matchedAttrName,
		const QString & matchedContent);

	/**
	 * Deletes the node
	 *
	 * \param [in]     dom	           the xml dom.
	 * \param [in]	   nodeName	       �ڵ�����.
	 *
	 * \returns True if it succeeds, false if it fails.
	 */

	static bool deleteNode(QDomDocument *dom, const QString & nodeName);

	/**
	 * Deletes the node
	 *
	 * \param [in]     dom	           the xml dom.
	 * \param [in]	   nodeName	       �ڵ�����.
	 * \param [in]	   matchedAttrName ��Ҫ����ƥ�����������.
	 * \param [in]	   matchedContent  ��Ҫ����ƥ�������ֵ.
	 *
	 * \returns True if it succeeds, false if it fails.
	 */

	static bool deleteNode(QDomDocument *dom, const QString & nodeName,
		const QString &matchedAttrName, const QString & matchedContent);

	/**
	 * Deletes the node attribute
	 *
	 * \param [in]     dom	           the xml dom.
	 * \param [in]	   nodeName	       �ڵ�����.
	 * \param [in]	   attrName	       ��������.			   
	 *
	 * \returns True if it succeeds, false if it fails.
	 */

	static bool deleteNodeAttr(QDomDocument *dom, const QString & nodeName, QString attrName);

	/**
	 * Modified node text content
	 *
	 * \param [in]     dom	           the xml dom.
	 * \param [in]	   nodeName	       �ڵ�����.
	 * \param [in]	   newText	       �ı�.
	 *
	 * \returns True if it succeeds, false if it fails.
	 */

	static bool modifiedContent(QDomDocument *dom, const QString & nodeName, const QString &newText);

	/**
	 * Modified node attribute content
	 *
	 * \param [in]     dom	           the xml dom.
	 * \param [in]	   nodeName	       �ڵ�����.
	 * \param [in]	   attrName	       ��������.
	 * \param [in]	   newAttr	       ����ֵ.
	 *
	 * \returns True if it succeeds, false if it fails.
	 */

	static bool modifiedContent(QDomDocument * dom, const QString & nodeName,
		const QString& attrName, const QString& newAttr);

	/**
	 * Modified content
	 *
	 * \param [in]     dom	           the xml dom.
	 * \param [in]	   nodeName	       �ڵ�����.
	 * \param [in]	   matchedAttrName ��Ҫ����ƥ�����������.
	 * \param [in]	   matchedContent  ��Ҫ����ƥ�������ֵ.
	 * \param [in]	   attrName	       ��������.
	 * \param [in]	   newAttr	       ����ֵ.
	 *
	 * \returns True if it succeeds, false if it fails.
	 */

	static bool modifiedContent(QDomDocument *dom, const QString & nodeName,
		const QString &matchedAttrName, const QString & matchedContent,
		const QString& attrName, const QString& newAttr);

	//! ���xml����ָ��*/
	static void appendRootXMLProcessingInstruction(QDomDocument *dom);

	/*! ���rootԪ�أ�����������ӵ�Ԫ��*/
	static QDomElement appendRootElement(QDomDocument *dom, QString name,
		QString& createTime = QString());

	//*!�����е�Ԫ������µ�DomԪ��,����������ӵ�Ԫ��*/
	static QDomElement appendDomElement(QDomElement &rDomElement, const QString elementName);

	/*!�����е�Ԫ������ı�����*/
	static QDomText appendText(QDomDocument *dom, QDomElement &rDomElement, 
		const QString &rText);

	/*!��ȡ��domԪ�أ�����������ڣ������������*/
	static QDomElement getOrAppendNewDomElement(QDomElement &rDomElement, 
		const QString elementName);

	/*!��Ӱ���һ���ı��ڵ��DomԪ��*/
	static QDomElement appendDomTextNode(QDomElement &rDomElement, 
		const QString elementName, const QString text);

	/*!��Ӱ���һ��bool�ı��ڵ��DomԪ��*/
	static QDomElement appendDomBooleanNode(QDomElement &rDomElement, 
		const QString elementName, const bool value);

	/*!������Ӱ���һ���ı��ڵ��DomԪ��(����һ������ֵ)*/
	static QDomElement appendDomIntegerNode(QDomElement &rDomElement, 
		const QString elementName, const int val);

	/*!��Ӱ���һ���ı��ڵ��DomԪ��(����һ������ֵ)*/
	static QDomElement appendDomDoubleValueNode(QDomElement &rDomElement, \
		const QString elementName, \
		const double val, \
		const char format, \
		const int precision);

	/*!��Ӱ���һ���ı��ڵ��DomԪ��(������������ֵ)*/
	static QDomElement appendDomDoubleValueNode2(QDomElement &rDomElement, \
		const QString elementName, \
		const double a, \
		const double b, \
		const char format, \
		const int precision);

	/*!��Ӱ���һ���ı��ڵ��DomԪ��(����N������ֵ)*/
	static QDomElement appendDomDoubleValueNodeN(QDomElement &rDomElement, \
		const QString elementName, \
		const QVector<double> &rValues, \
		const char format, \
		const int precision);

	/*!��DomԪ�����double (float��double)���ԣ�ͬʱȷ��С������"."������","*/
	static void setQrealAttribute(QDomElement domElement, \
		const QString attrName, \
		const double attrValue, \
		const int precision, \
		const char format);

	static QDomComment appendComment(QDomElement &rDomElement, const QString &rComment); /*!��ע��*/

	/**@brief API for ����xml*/
	static QDomElement loadXMLDomDocument(QFile &rFile, QDomDocument *domDocument, const QString& rootTagName, QString &error);

	/*!��������һ���ı��ڵ��һ��DOMԪ��*/
	static QString parseDomTextNode(QDomElement domElement, const QString &rDefaultValue = "");

	/*!��������һ���ı��ڵ��һ��DOMԪ��(����3������ֵ)*/
	static void parseDomDoubleValueNode3(QDomElement &domElement, double &rA, double &rB, double &rC);

	/*!��������һ���ı��ڵ��һ��DOMԪ��(����2������ֵ)*/
	static void parseDomDoubleValueNode2(QDomElement &domElement, double &rA, double &rB);

	/*!��������һ���ı��ڵ��һ��DOMԪ��(����1������ֵ),����һ��Ĭ��ֵ��������Ϊ��ʱ����Ĭ��ֵ*/
	static double parseDomDoubleValueNode(QDomElement &domElement, const double defaultValue);

	/*!��������һ���ı��ڵ��һ��DOMԪ��(����1������ֵ)������һ��Ĭ��ֵ��������Ϊ��ʱ����Ĭ��ֵ*/
	static int parseDomIntegerNode(QDomElement &domElement, const int defaultValue);

	/*!��������һ���ı��ڵ��һ��DOMԪ��(����1������ֵ)������һ��Ĭ��ֵ��������Ϊ��ʱ����Ĭ��ֵ*/
	static bool parseDomBooleanNode(QDomElement &domElement, const bool defaultValue);
	static bool parseAttributeBool(const QDomElement &domElement, const QString attributeName, const bool defaultValue);
	static void parseSimulationTimeTag(QDomElement &domElement, QString &rStart, QString &rStep, QString &rStop, bool &rInheritTs);

	static bool verifyProjectFileVersion(const QString & version);
	static bool verifySolutionFileVersion(const QString & version);
	static const QString generateCreateTime();

	static bool saveDom(QDomDocument* dom,const QString& savePath);
	
private:
	explicit XmlUtils() {}
};

JIN_END_NAMESPACE
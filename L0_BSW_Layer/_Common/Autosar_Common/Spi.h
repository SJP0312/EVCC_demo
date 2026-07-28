#ifndef AUTOSAR_COMMON_SPI_H
#define AUTOSAR_COMMON_SPI_H

#include "Std_Types.h"

#define SPI_AR_RELEASE_MAJOR_VERSION 4u
#define SPI_AR_RELEASE_MINOR_VERSION 1u

#ifndef SPI_APPL_DATA
# define SPI_APPL_DATA AUTOMATIC
#endif

#ifndef SPI_CONST
# define SPI_CONST
#endif

#ifndef SPI_VAR
# define SPI_VAR
#endif

typedef uint8 Spi_DataBufferType;
typedef uint8 Spi_DataType;
typedef uint8 Spi_ChannelType;
typedef uint8 Spi_SequenceType;
typedef uint8 Spi_SeqResultType;

#define SPI_SEQ_OK        ((Spi_SeqResultType)0u)
#define SPI_SEQ_PENDING   ((Spi_SeqResultType)1u)
#define SPI_SEQ_FAILED    ((Spi_SeqResultType)2u)
#define SPI_SEQ_CANCELLED ((Spi_SeqResultType)3u)

#define Spi_SeqData ((Spi_SequenceType)0u)
#define Spi_SeqReg  ((Spi_SequenceType)1u)
#define Spi_ChlCmd  ((Spi_ChannelType)0u)
#define Spi_ChlReg  ((Spi_ChannelType)1u)
#define Spi_ChlData ((Spi_ChannelType)2u)

static inline Std_ReturnType Spi_SyncTransmit(Spi_SequenceType Sequence)
{
  (void)Sequence;
  return E_OK;
}

static inline Std_ReturnType Spi_AsyncTransmit(Spi_SequenceType Sequence)
{
  (void)Sequence;
  return E_OK;
}

static inline Spi_SeqResultType Spi_GetSequenceResult(Spi_SequenceType Sequence)
{
  (void)Sequence;
  return SPI_SEQ_OK;
}

static inline Std_ReturnType Spi_SetupEB(Spi_ChannelType Channel, const Spi_DataBufferType* SrcDataBufferPtr, Spi_DataBufferType* DesDataBufferPtr, uint16 Length)
{
  (void)Channel;
  (void)SrcDataBufferPtr;
  (void)DesDataBufferPtr;
  (void)Length;
  return E_OK;
}

static inline Std_ReturnType Spi_WriteIB(Spi_ChannelType Channel, const Spi_DataType* DataBufferPtr)
{
  (void)Channel;
  (void)DataBufferPtr;
  return E_OK;
}

static inline Std_ReturnType Spi_ReadIB(Spi_ChannelType Channel, Spi_DataType* DataBufferPointer)
{
  (void)Channel;
  (void)DataBufferPointer;
  return E_OK;
}

#endif /* AUTOSAR_COMMON_SPI_H */

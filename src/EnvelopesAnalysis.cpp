#include "EnvelopesAnalysis.hpp"

#include "EnvelopesContainer.hpp"
#include "EnvelopeComparator.hpp"

void* InitializeEnvelopesContainer()
{
    EnvelopesContainer* envelopes_container = new EnvelopesContainer(10.0, 10.0, 15.0, 15.0);
    
    return (void*)envelopes_container;
}

bool CanOneEnvelopeContainAnother(void* container)
{
    EnvelopesContainer* envelopes_container = (EnvelopesContainer*)container;

    Envelope* envelope_1 = envelopes_container->get_envelope_1();
    Envelope* envelope_2 = envelopes_container->get_envelope_2();

    return EnvelopeComparator::CanOneContainAnother(envelope_1, envelope_2);
}